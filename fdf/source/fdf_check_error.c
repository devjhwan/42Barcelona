/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_check_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:02:33 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/15 11:02:35 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_check_error.h"

int	check_filename(const char *filename)
{
	char	*f_extension;

	f_extension = ft_strchr(filename, '.');
	if (f_extension == NULL)
		return (errmsg(FILENAME_ERR), 0);
	if (ft_strncmp(f_extension, ".fdf", 5) == 0)
		return (1);
	else
		return (errmsg(FILENAME_ERR), 0);
}

int	check_regex(const char *value)
{
	int	i;

	i = 0;
	while (ft_isdigit(value[i]))
		i++;
	if (value[i] != ',' && value[i] != '\0')
		return (errmsg(REGEX_ERR), 0);
	if (value[i] == ',')
	{
		if (value[i + 1] != '0' && value[i + 2] != 'x')
			return (errmsg(REGEX_ERR), 0);
		i += 3;
		while (ft_isdigit(value[i]) || \
							(value[i] >= 'A' && value[i] <= 'F') || \
							(value[i] >= 'a' && value[i] <= 'f'))
			i++;
		if (value[i] == '\0')
			return (1);
		else
			return (errmsg(REGEX_ERR), 0);
	}
	return (1);
}

int	check_col(char **line_sep)
{
	static int	prev_row_count;
	static int	start;
	int			count;

	count = 0;
	while (line_sep[count] != NULL)
		count++;
	if (start == 0)
	{
		prev_row_count = count;
		start = 1;
		return (1);
	}
	else
	{
		if (count != prev_row_count)
			return (errmsg(ELEM_COUNT_ERR), 0);
		else
			return (1);
	}
}

int	check_line_content(const char *line)
{
	char	**line_sep;
	int		i;

	if (line == NULL)
		return (0);
	line_sep = ft_split(line, " \n");
	if (line_sep == NULL)
		return (errmsg(MALLOC_ALLOCATION_ERR), 0);
	if (!check_col(line_sep))
		return (free_2d(line_sep), errmsg(CORRUPTED_CONTENT_ERR), 0);
	i = 0;
	while (line_sep[i] != NULL)
		if (!check_regex(line_sep[i++]))
			return (free_2d(line_sep), errmsg(CORRUPTED_CONTENT_ERR), 0);
	free_2d(line_sep);
	return (1);
}

int	check_file_corruption(const char *filename)
{
	char	*line;
	int		fd;

	if (!check_filename(filename))
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (errmsg(FILE_NOT_EXISTING_ERR), 0);
	line = get_next_line(fd);
	if (line == NULL)
		return (close(fd), errmsg(EMPTY_FILE_ERR), 0);
	while (line != NULL)
	{
		if (!check_line_content(line))
			return (close(fd), free(line), 0);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}
