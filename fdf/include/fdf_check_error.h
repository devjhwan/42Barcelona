/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_check_error.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:11:05 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/15 11:11:06 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_CHECK_ERROR_H
# define FDF_CHECK_ERROR_H

# include <fcntl.h>
# include "libft.h"

# define FILENAME_ERR 1
# define REGEX_ERR 2
# define ELEM_COUNT_ERR 3
# define CORRUPTED_CONTENT_ERR 4
# define FILE_NOT_EXISTING_ERR 5
# define MALLOC_ALLOCATION_ERR 6
# define EMPTY_FILE_ERR 7

int		check_filename(const char *filename);
int		check_regex(const char *value);
int		check_col(char **line_sep);
int		check_line_content(const char *line);
int		check_file_corruption(const char *filename);
void	free_2d(char **var);
void	errmsg(int errno);
#endif
