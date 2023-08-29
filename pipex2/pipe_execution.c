/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:16:36 by junghwle          #+#    #+#             */
/*   Updated: 2023/08/29 17:28:04 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	dup_handler(t_pack *pack, int *fd, int process)
{
	if (process == MIDDLE)
	{
		close(fd[0]);
		if (pack->fd1 < 0)
			file_error(pack->file1);
		if (dup2(pack->fd1, STDIN_FILENO) < 0)
			errexit(NULL, 1);
		if (dup2(fd[1], STDOUT_FILENO) < 0)
			errexit(NULL, 1);
		close(pack->fd1);
	}
	else
	{
		close(fd[0]);
		close(fd[1]);
		if (pack->fd2 < 0)
			file_error(pack->file2);
		if (dup2(pack->fd1, STDIN_FILENO) < 0)
			errexit(NULL, 1);
		if (dup2(pack->fd2, STDOUT_FILENO) < 0)
			errexit(NULL, 1);
		close(pack->fd1);
		close(pack->fd2);
	}
	return (0);
}

static void	middle_process(t_pack *pack, char **envp, char **cmd)
{
	int		fd[2];
	pid_t	parent;
	char	*path;

	path = NULL;
	pipe(fd);
	parent = fork();
	if (parent < 0)
		errexit(pack, 1);
	else if (parent == 0)
	{
		if (ft_strcmp(cmd[0], "exit") == 0)
			exit(ft_atoi(cmd[1]));
		dup_handler(pack, fd, MIDDLE);
		path = get_path(pack, cmd[0]);
		if (execve(path, cmd, envp) < 0)
			errexit(NULL, 1);
	}
	free(path);
	pack->fd1 = fd[0];
	close(fd[1]);
}

static void	final_process(t_pack *pack, char **envp, char **cmd)
{
	int		fd[2];
	int		status;
	pid_t	parent;
	char	*path;

	path = NULL;
	pipe(fd);
	parent = fork();
	if (parent < 0)
		errexit(pack, 1);
	else if (parent == 0)
	{
		if (ft_strcmp(cmd[0], "exit") == 0)
			exit(ft_atoi(cmd[1]));
		path = get_path(pack, cmd[0]);
		dup_handler(pack, fd, FINAL);
		if (execve(path, cmd, envp) < 0)
			errexit(NULL, EXIT_FAILURE);
	}
	waitpid(parent, &status, 0);
	pack->exit_code = WEXITSTATUS(status);
	close(fd[0]);
	close(fd[1]);
	free(path);
}

void	pipe_execution(t_pack *pack, char **envp)
{
	t_list	*cmd;

	cmd = pack->cmd;
	while (cmd != NULL)
	{
		if (cmd->next != NULL)
			middle_process(pack, envp, (char **)cmd->content);
		else
			final_process(pack, envp, (char **)cmd->content);
		cmd = cmd->next;
	}
}
