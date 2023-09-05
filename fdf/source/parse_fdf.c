/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:53:09 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/04 19:16:15 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_map.h"

void	map_init(t_map *map, char **line_sep)
{
	int	i;
	int	j;
	int	str_j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		str_j = 0;
		while (j < map->col)
		{
			map->matrix[i][j] = ft_atoi(&line_sep[i][str_j++]);
			if (line_sep[i][str_j] == ',')
			{
				map->color[i][j] = ft_atoi_base(&line_sep[i][str_j + 3], \
									"0123456789ABCDEF");
			}
			while (line_sep[i][str_j] != ' ' && line_sep[i][str_j] != '\0')
				str_j++;
			str_j++;
			j++;
		}
		i++;
	}
}

int	elem_count(char *line, int sep)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != sep)
		{
			count++;
			while (line[i] != sep && line[i] != '\0')
				i++;
		}
		i++;
	}
	return (count);
}

void	*get_map_matrix(char *line)
{
	t_map	*map;
	char	**line_sep;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (map == NULL)
		return (NULL);
	line_sep = ft_split(line, "\n");
	if (line_sep == NULL)
		return (free(map), NULL);
	map->row = 0;
	while (line_sep[map->row] != NULL)
		map->row++;
	map->col = elem_count(line_sep[0], ' ');
	map->matrix = (int **)get_matrix2d(map->row, map->col, \
					sizeof(int));
	map->color = (unsigned int **)get_matrix2d(map->row, map->col, \
					sizeof(int));
	if (map->matrix == NULL || map->color == NULL)
		return (free_matrix2d(map->matrix), free_matrix2d(map->color), \
				free_matrix2d(line_sep), free(map), NULL);
	map_init(map, line_sep);
	free_matrix2d(line_sep);
	return (map);
}

int	get_file_bytes(char *file_name)
{
	int		fd;
	int		byte;
	int		ret;
	char	*line;

	line = (char *)malloc(sizeof(char) * (KILOBYTE + 1));
	fd = open(file_name, O_RDONLY);
	if (fd < 0 || line == NULL)
		return (close(fd), free(line), -1);
	ret = 1;
	byte = 0;
	while (ret > 0)
	{
		ret = read(fd, line, KILOBYTE);
		if (ret < 0)
			return (close(fd), free(line), -1);
		if (ret > 0)
			byte += ret;
	}
	close(fd);
	free(line);
	return (byte);
}

t_map	*parse_fdf(char *fdf_file)
{
	int		fd;
	int		byte;
	char	*line;
	t_map	*map;

	byte = get_file_bytes(fdf_file);
	if (byte < 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) *(byte + 1));
	fd = open(fdf_file, O_RDONLY);
	if (fd < 0 || line == NULL)
		return (close(fd), free(line), NULL);
	if (read(fd, line, byte) < 0)
		return (close(fd), free(line), NULL);
	close(fd);
	line[byte] = '\0';
	map = get_map_matrix(line);
	free(line);
	return (map);
}
