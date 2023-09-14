/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_loop_hook3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:51:14 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/10 21:51:15 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_mouse(t_mlx *mlx, t_map *map, t_fdf_flag *flag)
{
	if (flag->mouse & FLAG_LEFT_MOUSE)
	{
		if ((flag->mouse_v[0] == 0 && flag->mouse_v[1] == 0) || \
			(flag->mouse_v[0] == INT_MIN && flag->mouse_v[1] == INT_MIN))
			return ;
		map->transform.position[0] += flag->mouse_v[0];
		map->transform.position[1] += flag->mouse_v[1];
		reshape(map);
		draw_shape(mlx, map);
	}
}

void	scale_mouse(t_mlx *mlx, t_map *map, t_fdf_flag *flag)
{
	if (flag->mouse & FLAG_SCROLL_UP)
	{
		map->transform.scale[0] *= 1.15;
		map->transform.scale[1] *= 1.15;
		map->transform.scale[2] *= 1.15;
		flag->mouse &= ~FLAG_SCROLL_UP;
	}
	else if (flag->mouse & FLAG_SCROLL_DOWN)
	{
		map->transform.scale[0] *= 0.85;
		map->transform.scale[1] *= 0.85;
		map->transform.scale[2] *= 0.85;
		flag->mouse &= ~FLAG_SCROLL_DOWN;
	}
	reshape(map);
	draw_shape(mlx, map);
}

void	rotate_mouse(t_mlx *mlx, t_map *map, t_fdf_flag *flag)
{
	t_quat	quaternion;
	double	v_mod;
	double	v[2];

	if (flag->mouse & FLAG_RIGHT_MOUSE)
	{
		if ((flag->mouse_v[0] == 0 && flag->mouse_v[1] == 0) || \
			(flag->mouse_v[0] == INT_MIN && flag->mouse_v[1] == INT_MIN))
			return ;
		v_mod = sqrt(flag->mouse_v[0] * flag->mouse_v[0] + \
					flag->mouse_v[1] * flag->mouse_v[1]);
		v[0] = flag->mouse_v[0] / v_mod;
		v[1] = flag->mouse_v[1] / v_mod;
		quaternion_from_axisangle((double []){-v[1], v[0], 0}, \
								M_PI / 18, &quaternion);
		quaternion_multiply(&quaternion, &map->transform.quaternion, \
			&map->transform.quaternion);
		reshape(map);
		draw_shape(mlx, map);
	}
}
