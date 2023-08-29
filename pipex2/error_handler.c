/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:27:30 by junghwle          #+#    #+#             */
/*   Updated: 2023/08/29 16:29:11 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_pack(t_pack *pack)
{
	if (pack != NULL)
	{
		close(pack->fd1);
		close(pack->fd2);
		if (pack->here_doc == 1)
		{
			unlink(".heredoc_tmp");
			pack->here_doc = 0;
		}
		ft_lstclear(&pack->cmd, clear_content);
		free_strarr(pack->path_set);
		free(pack);
		pack = NULL;
	}
}

void	free_strarr(char **strarr)
{
	int	i;

	i = 0;
	while (strarr[i] != NULL)
		free(strarr[i++]);
	free(strarr);
}

void	clear_content(void *content)
{
	free_strarr((char **)content);
}

void	errexit(t_pack *pack, int exit_code)
{
	perror("pipex");
	free_pack(pack);
	exit(exit_code);
}
