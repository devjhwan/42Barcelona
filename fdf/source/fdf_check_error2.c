/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_check_error2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:02:33 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/15 11:02:35 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_check_error.h"

void	free_2d(char **var)
{
	int	i;

	i = 0;
	while (var[i] != NULL)
		free(var[i++]);
	free(var);
}

void	errmsg(int errno)
{
	if (errno == FILENAME_ERR)
		ft_putstr_fd("fdf: file extension error\n", 2);
	else if (errno == REGEX_ERR)
		ft_putstr_fd("fdf: value regex error\n", 2);
	else if (errno == ELEM_COUNT_ERR)
		ft_putstr_fd("fdf: content count error\n", 2);
	else if (errno == CORRUPTED_CONTENT_ERR)
		ft_putstr_fd("fdf: corrupted content error\n", 2);
	else if (errno == FILE_NOT_EXISTING_ERR)
		ft_putstr_fd("fdf: not existing file error\n", 2);
	else if (errno == MALLOC_ALLOCATION_ERR)
		ft_putstr_fd("fdf: malloc allocation error\n", 2);
	else if (errno == EMPTY_FILE_ERR)
		ft_putstr_fd("fdf: empty file error\n", 2);
}
