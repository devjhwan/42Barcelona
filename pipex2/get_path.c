/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:57:42 by junghwle          #+#    #+#             */
/*   Updated: 2023/08/29 17:25:12 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*check_root_path(char *path, char *cmd)
{
	if (errno != 0 && access(cmd, X_OK) >= 0)
	{
		errno = 0;
		return (ft_strdup(cmd));
	}
	return (path);
}

char	*get_path(t_pack *pack, char *cmd)
{
	int		i;
	char	*path;

	if (pack->path_set == NULL)
		return (NULL);
	i = 0;
	while (pack->path_set[i] != NULL)
	{
		path = ft_strjoin(3, pack->path_set[i++], "/", cmd);
		if (path == NULL)
			break ;
		if (access(path, X_OK) >= 0)
		{
			errno = 0;
			break ;
		}
		free(path);
	}
	path = check_root_path(path, cmd);
	if (errno != 0)
		command_error(cmd);
	return (path);
}
