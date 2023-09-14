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

void	translate_keyboard(t_mlx *mlx, t_map *map, t_fdf_flag *flag)
{
	double		speed;

	if (flag->key & FLAG_T)
	{
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

void	scale_keyboard2(t_map *map, t_fdf_flag *flag)
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
}

void	scale_keyboard(t_mlx *mlx, t_map *map, t_fdf_flag *flag)
{
	if (flag->key & FLAG_S)
	{
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
		if (!map->issphere)
			scale_keyboard2(map, flag);
		reshape(map);
		draw_shape(mlx, map);
	}
}

void	rotate_keyboard(t_mlx *mlx, t_map *map, t_fdf_flag *flag)
{
	t_quat	quaternion;
	
	if (flag->key & FLAG_R)
	{
		quaternion_identity(&quaternion);
		if (flag->arrow & FLAG_UP)
			quaternion_from_axisangle((double []){1, 0, 0}, \
								M_PI / 36, &quaternion);
		else if (flag->arrow & FLAG_DOWN)
			quaternion_from_axisangle((double []){1, 0, 0}, \
								-M_PI / 36, &quaternion);
		quaternion_multiply(&quaternion, &map->transform.quaternion, \
			&map->transform.quaternion);
		if (flag->arrow & FLAG_LEFT)
			quaternion_from_axisangle((double []){0, 1, 0}, \
								-M_PI / 36, &quaternion);
		else if (flag->arrow & FLAG_RIGHT)
			quaternion_from_axisangle((double []){0, 1, 0}, \
								M_PI / 36, &quaternion);
		quaternion_multiply(&quaternion, &map->transform.quaternion, \
			&map->transform.quaternion);
		reshape(map);
		draw_shape(mlx, map);
	}
}

void	back_to_original_shape(t_mlx *mlx, t_map *map, t_fdf_flag *flag)
{
	if (flag->key == FLAG_Q)
	{
		map->issphere = 0;
		shape_initialize(map);
		draw_shape(mlx, map);
		flag->key = 0;
	}
}

void	set_to_spherical_perspective(t_mlx *mlx, t_map *map, t_fdf_flag *flag)
{
	if (flag->key == FLAG_H)
	{
		map->issphere = 1;
		set_spherical_perspective(map);
		draw_shape(mlx, map);
		flag->key = 0;
	}
}

int	render_frame_hook(void *fdf_pack[3])
{
	t_mlx		*mlx;
	t_map		*map;
	t_fdf_flag	*flag;

	mlx = (t_mlx *)fdf_pack[0];
	map = (t_map *)fdf_pack[1];
	flag = (t_fdf_flag *)fdf_pack[2];
	translate_keyboard(mlx, map, flag);
	scale_keyboard(mlx, map, flag);
	rotate_keyboard(mlx, map, flag);
	back_to_original_shape(mlx, map, flag);
	set_to_spherical_perspective(mlx, map, flag);
	return (0);
}
