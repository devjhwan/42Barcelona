/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:44:40 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/10 23:34:01 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_map.h"

static void	init_position(t_map *map, t_transform *transform)
{
	double	md_x;
	double	md_y;

	md_x = get_middle_distance(map, 0);
	md_y = get_middle_distance(map, 1);
	translate_matrix(map->matrix, map->len, (double []){-md_x, -md_y, 0});
	transform->position[0] = 0;
	transform->position[1] = 0;
}

static void	init_rotation(t_map *map, t_transform *transform)
{
	t_quat	quaternion1;
	t_quat	quaternion2;

	quaternion_from_axisangle((double []){0, 0, 1}, \
								M_PI / 4, &quaternion1);
	quaternion_from_axisangle((double []){1, 0, 0}, \
								asin(tan(M_PI / 6)), &quaternion2);
	quaternion_multiply(&quaternion2, &quaternion1, &transform->quaternion);
	rotate_matrix(map->matrix, map->len, &transform->quaternion);
}

static void	init_scale(t_map *map, t_transform *transform)
{
	double	range_x;
	double	range_y;
	double	range_z;
	double	proyection_scale;

	proyection_scale = sin(M_PI / 4) * tan(M_PI / 6);
	range_x = get_range(map, 0);
	range_y = get_range(map, 1);
	range_z = get_range(map, 2);
	transform->scale[0] = HEIGHT / range_x * proyection_scale * 1.5;
	transform->scale[1] = HEIGHT / range_y * proyection_scale * 1.5;
	transform->scale[2] = HEIGHT / range_z * 0.15;
	scale_matrix(map->matrix, map->len, \
				(double []){transform->scale[0], \
							transform->scale[1], \
							transform->scale[2]});
}

void	shape_initialize(t_map *map)
{
	t_transform	*transform;

	transform = &map->transform;
	ft_memcpy(map->matrix, map->m_copy, \
				sizeof(double) * map->row * map->col * 3);
	init_scale(map, transform);
	init_rotation(map, transform);
	init_position(map, transform);
}
