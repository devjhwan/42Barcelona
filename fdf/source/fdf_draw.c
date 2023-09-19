/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:17:12 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/06 17:17:14 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_draw.h"

static void	mlx_clear_img(t_img *img)
{
	int		x;
	int		y;
	char	*dst;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			dst = img->addr + (y * img->size_line + x * \
					(img->bits_per_pixel / 8));
			*(unsigned int *)dst = 0;
			x++;
		}
		y++;
	}
}

void	select_point(t_mlx *mlx, t_map *map, int n)
{
	draw_horitzontal_line(mlx, map, n);
	draw_vertical_line(mlx, map, n);
}

void	draw_shape(t_mlx *mlx, t_map *map)
{
	int		n;

	mlx_clear_img(mlx->img);
	mlx_clear_window(mlx->mlx, mlx->mlx_win);
	if (map->len == 3)
		draw_point(mlx, map, 0);
	else if (map->matrix[(map->row * map->col - map->row) * 3 + 2] > 0)
	{
		n = 0;
		while (n < map->len)
		{
			select_point(mlx, map, n);
			n += 3;
		}
	}
	else
	{
		n = map->len - 3;
		while (n >= 0)
		{
			select_point(mlx, map, n);
			n -= 3;
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img->img, 0, 0);
}
