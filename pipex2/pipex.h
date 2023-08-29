/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:37:01 by junghwle          #+#    #+#             */
/*   Updated: 2023/08/29 17:18:03 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include "libft.h"

# define MIDDLE 0
# define FINAL 1

typedef struct s_pack
{
	int		here_doc;
	char	*endstream;
	char	*file1;
	char	*file2;
	int		fd1;
	int		fd2;
	t_list	*cmd;
	char	**path_set;
	int		exit_code;
}	t_pack;

t_pack	*parse_input(int argc, char **argv, char **envp);
t_pack	*parse_input2(t_pack *pack, int argc, char **argv, char **envp);
void	pipe_execution(t_pack *pack, char **envp);
char	*get_path(t_pack *pack, char *cmd);

void	free_pack(t_pack *pack);
void	free_strarr(char **strarr);
void	clear_content(void *content);
void	errexit(t_pack *pack, int exit_code);

void	file_error(char *file_name);
void	command_error(char *cmd);

int		test_func(void);

#endif
