/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:44:40 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/10 15:44:42 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_map.h"

void	matrix_initialize(t_map *map, char **line_sep);

static int	elem_count(char *line, int sep)
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

static void	*get_map_matrix(t_map *map, char *line)
{
	char	**line_sep;

	line_sep = ft_split(line, "\n");
	if (line_sep == NULL)
		return (free(map), free(line), NULL);
	map->row = 0;
	while (line_sep[map->row] != NULL)
		map->row++;
	map->col = elem_count(line_sep[0], ' ');
	map->len = map->row * map->col * 3;
	map->matrix = (double *)malloc(sizeof(double) * map->row * map->col * 3);
	map->m_copy = (double *)malloc(sizeof(double) * map->row * map->col * 3);
	map->color = (unsigned int *)ft_calloc(map->row * map->col, sizeof(int));
	map->c_copy = (unsigned int *)ft_calloc(map->row * map->col, sizeof(int));
	if (map->matrix == NULL || map->color == NULL || \
		map->m_copy == NULL || map->c_copy == NULL)
		return (free_map(map), free_matrix2d(line_sep), free(line), NULL);
	matrix_initialize(map, line_sep);
	ft_memcpy(map->m_copy, map->matrix, \
				sizeof(double) * map->len);
	ft_memcpy(map->m_copy, map->matrix, \
				sizeof(unsigned int) * map->len / 3);
	free_matrix2d(line_sep);
	return (free(line), map);
}

static int	get_file_bytes(char *file_name)
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

void	*map_initialize(t_map *map, char *fdf_filename)
{
	int		fd;
	int		byte;
	char	*line;

	ft_bzero(map, sizeof(t_map));
	byte = get_file_bytes(fdf_filename);
	if (byte < 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) *(byte + 1));
	fd = open(fdf_filename, O_RDONLY);
	if (fd < 0 || line == NULL)
		return (close(fd), free(line), NULL);
	if (read(fd, line, byte) < 0)
		return (close(fd), free(line), NULL);
	close(fd);
	line[byte] = '\0';
	if (get_map_matrix(map, line) == NULL)
		return (NULL);
	shape_initialize(map);
	return (map);
}
