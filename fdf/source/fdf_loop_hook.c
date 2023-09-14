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

void	translate_keyboard(t_mlx *mlx, t_map *map, t_fdf_flag *flag);
void	scale_keyboard(t_mlx *mlx, t_map *map, t_fdf_flag *flag);
void	rotate_keyboard(t_mlx *mlx, t_map *map, t_fdf_flag *flag);

void	translate_mouse(t_mlx *mlx, t_map *map, t_fdf_flag *flag);
void	scale_mouse(t_mlx *mlx, t_map *map, t_fdf_flag *flag);
void	rotate_mouse(t_mlx *mlx, t_map *map, t_fdf_flag *flag);

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
	translate_mouse(mlx, map, flag);
	scale_mouse(mlx, map, flag);
	rotate_mouse(mlx, map, flag);
	back_to_original_shape(mlx, map, flag);
	set_to_spherical_perspective(mlx, map, flag);
	return (0);
}
