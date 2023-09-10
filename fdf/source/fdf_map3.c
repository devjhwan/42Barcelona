/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:44:40 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/10 15:44:42 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_map.h"

double	get_middle_distance(t_map *map, int axis);
double	get_range(t_map *map, int axis);

static void	init_position(t_map *map, t_transform *transform)
{
	double	md_x;
	double	md_y;

	md_x = get_middle_distance(map, 0);
	md_y = get_middle_distance(map, 1);
	translate_matrix(map, (double []){-md_x, -md_y, 0});
	transform->position[0] = 0;
	transform->position[1] = 0;
	transform->position[2] = 0;
}

static void	init_rotation(t_map *map, t_transform *transform)
{
	rotate_matrix(map, (double []){0, 0, 1}, M_PI / 4);
	rotate_matrix(map, (double []){1, 0, 0}, atan(1 / sqrt(2)));
	transform->rotate[0] = atan(1 / sqrt(2));
	transform->rotate[1] = 0;
	transform->rotate[2] = M_PI / 4;
}

static void	init_scale(t_map *map, t_transform *transform)
{
	double range_x;
	double range_y;

	range_x = get_range(map, 0);
	range_y = get_range(map, 1);
	scale_matrix(map, (double []){HEIGHT / range_x * 0.7, 
								HEIGHT / range_y * 0.7, 1});
	transform->scale[0] = 1;
	transform->scale[1] = 1;
	transform->scale[2] = 1;
}

void	shape_initialize(t_map *map)
{
	t_transform	*transform;

	transform = &map->transform;
	init_rotation(map, transform);
	init_position(map, transform);
	init_scale(map, transform);
}
