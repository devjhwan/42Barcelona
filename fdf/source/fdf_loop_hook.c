/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_loop_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:51:14 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/10 21:51:15 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_keyboard(void *fdf_pack[3])
{
	t_mlx		*mlx;
	t_map		*map;
	t_fdf_flag	*flag;
	double		speed;

	flag = (t_fdf_flag *)fdf_pack[2];
	if (flag->key & FLAG_T)
	{
		mlx = (t_mlx *)fdf_pack[0];
		map = (t_map *)fdf_pack[1];
		speed = 3;
		if (flag->arrow & FLAG_UP)
			map->transform.position[1] -= speed;
		if (flag->arrow & FLAG_DOWN)
			map->transform.position[1] += speed;
		if (flag->arrow & FLAG_LEFT)
			map->transform.position[0] -= speed;
		if (flag->arrow & FLAG_RIGHT)
			map->transform.position[0] += speed;
		reshape(map);
		draw_shape(mlx, map);
	}
}

void	scale_keyboard2(t_mlx *mlx, t_map *map, t_fdf_flag *flag)
{
	if ((flag->key & FLAG_X) && \
		(flag->arrow & FLAG_UP || flag->arrow & FLAG_RIGHT))
		map->transform.scale[0] *= 1.05;
	if ((flag->key & FLAG_X) && \
		(flag->arrow & FLAG_DOWN || flag->arrow & FLAG_LEFT))
		map->transform.scale[0] *= 0.95;
	if ((flag->key & FLAG_Y) && \
		(flag->arrow & FLAG_UP || flag->arrow & FLAG_RIGHT))
		map->transform.scale[1] *= 1.05;
	if ((flag->key & FLAG_Y) && \
		(flag->arrow & FLAG_DOWN || flag->arrow & FLAG_LEFT))
		map->transform.scale[1] *= 0.95;
	if ((flag->key & FLAG_Z) && \
		(flag->arrow & FLAG_UP || flag->arrow & FLAG_RIGHT))
		map->transform.scale[2] *= 1.05;
	if ((flag->key & FLAG_Z) && \
		(flag->arrow & FLAG_DOWN || flag->arrow & FLAG_LEFT))
		map->transform.scale[2] *= 0.95;
	reshape(map);
	draw_shape(mlx, map);
}

void	scale_keyboard(void *fdf_pack[3])
{
	t_mlx			*mlx;
	t_map			*map;
	t_fdf_flag		*flag;

	flag = (t_fdf_flag *)fdf_pack[2];
	if (flag->key & FLAG_S)
	{
		mlx = (t_mlx *)fdf_pack[0];
		map = (t_map *)fdf_pack[1];
		if (!(flag->key & ~FLAG_S) && \
			(flag->arrow & FLAG_UP || flag->arrow & FLAG_RIGHT))
		{
			map->transform.scale[0] *= 1.05;
			map->transform.scale[1] *= 1.05;
			map->transform.scale[2] *= 1.05;
		}
		else if (!(flag->key & ~FLAG_S) && \
			(flag->arrow & FLAG_DOWN || flag->arrow & FLAG_LEFT))
		{
			map->transform.scale[0] *= 0.95;
			map->transform.scale[1] *= 0.95;
			map->transform.scale[2] *= 0.95;
		}
		scale_keyboard2(mlx, map, flag);
	}
}

#include <stdio.h>

void	rotate_keyboard(void *fdf_pack[3])
{
	t_mlx		*mlx;
	t_map		*map;
	t_fdf_flag	*flag;
	t_quat	quaternion;
	
	flag = (t_fdf_flag *)fdf_pack[2];
	if (flag->key & FLAG_R)
	{
		mlx = (t_mlx *)fdf_pack[0];
		map = (t_map *)fdf_pack[1];
		quaternion_identity(&quaternion);
		
		//map->matrix[(map->row * map->col - map->row) * 3 + 2]

		if (flag->arrow & FLAG_UP)
			quaternion_from_axisangle((double []){1, 0, 0}, \
								M_PI / 36, &quaternion);
		if (flag->arrow & FLAG_DOWN)
			quaternion_from_axisangle((double []){1, 0, 0}, \
								-M_PI / 36, &quaternion);
		if (flag->arrow & FLAG_LEFT)
			quaternion_from_axisangle((double []){0, 1, 0}, \
								M_PI / 36, &quaternion);
		if (flag->arrow & FLAG_RIGHT)
			quaternion_from_axisangle((double []){0, 1, 0}, \
								-M_PI / 36, &quaternion);
		quaternion_multiply(&quaternion, &map->transform.quaternion, \
			&map->transform.quaternion);
		reshape(map);
		draw_shape(mlx, map);
	}
}

int	render_frame_hook(void *fdf_pack[3])
{
	translate_keyboard(fdf_pack);
	scale_keyboard(fdf_pack);
	rotate_keyboard(fdf_pack);
	return (0);
}
