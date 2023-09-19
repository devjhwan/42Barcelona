/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:44:40 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/10 15:44:42 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_map.h"
#define WHITE 0xFFFFFF

static void	fill_point(t_map *map, char **line_sep, int *arr)
{
	int	i;
	int	j;
	int	str_j;
	int	k;

	i = arr[0];
	j = arr[1];
	str_j = arr[2];
	k = arr[3];
	map->matrix[k] = (double)j;
	map->matrix[k + 1] = (double)i;
	map->matrix[k + 2] = (double)ft_atoi(&line_sep[i][str_j]);
	while (ft_isdigit(line_sep[i][str_j]) && line_sep[i][str_j] != '\0')
		str_j++;
	if (line_sep[i][str_j] == ',')
		map->color[k / 3] = ft_atoi_base(&line_sep[i][str_j + 3], \
								"0123456789ABCDEF");
	else
		map->color[k / 3] = WHITE;
}

void	matrix_initialize(t_map *map, char **line_sep)
{
	int	i;
	int	j;
	int	str_j;
	int	k;

	i = 0;
	k = 0;
	while (i < map->row)
	{
		j = 0;
		str_j = 0;
		while (j < map->col)
		{
			fill_point(map, line_sep, (int []){i, j, str_j, k});
			while (line_sep[i][str_j] != ' ' && line_sep[i][str_j] != '\0')
				str_j++;
			while (line_sep[i][str_j] == ' ' && line_sep[i][str_j] != '\0')
				str_j++;
			k += 3;
			j++;
		}
		i++;
	}
}
