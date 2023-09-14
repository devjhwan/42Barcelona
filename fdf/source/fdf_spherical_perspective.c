/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_spherical_perspective.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:31:19 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/14 12:31:20 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plane3d_to_sphere(t_map *map)
{
	int		n;
	double	latitude;
	double	longitude;
	double	radius;

	n = 0;
	radius = map->col / (2 * M_PI);
	while (n < map->len)
	{
		latitude = (map->matrix[n + 1] / map->row - 0.5) * M_PI;
		longitude = (map->matrix[n] / map->col - 0.5) * 2 * M_PI;
		map->matrix[n] = (radius + map->matrix[n + 2]) * \
							cos(latitude) * cos(longitude);
		map->matrix[n + 1] = (radius + map->matrix[n + 2]) * \
							cos(latitude) * sin(longitude);
		map->matrix[n + 2] = (radius + map->matrix[n + 2]) * \
							sin(latitude);
		n += 3;
	}
}

static void	init_position(t_map *map, t_transform *transform)
{
	double	md_x;
	double	md_y;

	md_x = get_middle_distance(map, 0);
	md_y = get_middle_distance(map, 1);
	translate_matrix(map, (double []){-md_x, -md_y, 0});
	transform->position[0] = 0;
	transform->position[1] = 0;
}

static void	init_scale(t_map *map, t_transform *transform)
{
	double	range;

	range = get_range(map, 0);
	transform->scale[0] = HEIGHT / range * 0.8;
	transform->scale[1] = HEIGHT / range * 0.8;
	transform->scale[2] = HEIGHT / range * 0.8;
	scale_matrix(map, (double []){transform->scale[0], \
									transform->scale[1], \
									transform->scale[2]});
}

void	set_spherical_perspective(t_map *map)
{
	t_transform	*transform;

	transform = &map->transform;
	ft_memcpy(map->matrix, map->m_copy, \
				sizeof(double) * map->row * map->col * 3);
	plane3d_to_sphere(map);
	init_scale(map, transform);
	init_position(map, transform);
	quaternion_identity(&transform->quaternion);
}
