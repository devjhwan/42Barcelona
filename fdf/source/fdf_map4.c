/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:44:40 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/10 15:44:42 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_map.h"

double	get_middle_distance(t_map *map, int axis)
{
	int		n;
	double	min;
	double	max;

	n = axis;
	min = map->matrix[n];
	max = map->matrix[n];
	while (n < map->len)
	{
		if (map->matrix[n] < min)
			min = map->matrix[n];
		else if (map->matrix[n] > max)
			max = map->matrix[n];
		n += 3;
	}
	return ((max + min) / 2);
}

double	get_range(t_map *map, int axis)
{
	int		n;
	double	min;
	double	max;

	n = axis;
	min = map->matrix[n];
	max = map->matrix[n];
	while (n < map->len)
	{
		if (map->matrix[n] < min)
			min = map->matrix[n];
		else if (map->matrix[n] > max)
			max = map->matrix[n];
		n += 3;
	}
	return (max - min);
}
