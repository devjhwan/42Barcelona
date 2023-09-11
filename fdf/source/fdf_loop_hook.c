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

int	render_frame_hook(void *fdf_pack[3])
{
	translate_keyboard(fdf_pack);
	return (0);
}
