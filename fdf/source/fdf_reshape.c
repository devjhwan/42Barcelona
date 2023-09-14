/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reshape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:03:22 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/11 17:03:24 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	scale(t_map *map, t_transform *transform)
{
	scale_matrix(map, (double []){transform->scale[0], \
									transform->scale[1], \
									transform->scale[2]});
}

static void	rotate(t_map *map, t_transform *transform)
{
	rotate_matrix(map, &transform->quaternion);
}

static void	translate(t_map *map, t_transform *transform)
{
	double	md_x;
	double	md_y;

	md_x = get_middle_distance(map, 0);
	md_y = get_middle_distance(map, 1);
	translate_matrix(map, (double []){-md_x + transform->position[0], \
										-md_y + transform->position[1], 0});
}

void	reshape(t_map *map)
{
	t_transform	*transform;

	transform = &map->transform;
	ft_memcpy(map->matrix, map->m_copy, \
				sizeof(double) * map->row * map->col * 3);
	if (map->issphere)
		plane3d_to_sphere(map);
	scale(map, transform);
	rotate(map, transform);
	translate(map, transform);
}
