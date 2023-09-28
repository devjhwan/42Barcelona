/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:17:12 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/06 17:17:14 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_draw.h"
#include "fdf_color.h"

void	ft_mlx_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	x += WIDTH / 2;
	y += HEIGHT / 2;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_mlx *mlx, double p[2], double q[2], unsigned int *color)
{
	double	v[2];
	double	v_n;
	double	k[2];
	double	ratio;

	v[0] = q[0] - p[0];
	v[1] = q[1] - p[1];
	v_n = sqrt(v[0] * v[0] + v[1] * v[1]);
	v[0] /= v_n;
	v[1] /= v_n;
	k[0] = p[0];
	k[1] = p[1];
	while (fabs(k[0] - q[0]) > 0.5 || fabs(k[1] - q[1]) > 0.5)
	{
		ratio = (sqrt((k[0] - p[0]) * (k[0] - p[0]) + \
						(k[1] - p[1]) * (k[1] - p[1])) / v_n);
		ft_mlx_pixel_put(mlx->img, (int)k[0], (int)k[1], \
						interpolate_color(ratio, color[0], color[1]));
		k[0] += v[0];
		k[1] += v[1];
	}
	ft_mlx_pixel_put(mlx->img, (int)q[0], (int)q[1], color[1]);
}

void	draw_horitzontal_line(t_mlx *mlx, t_map *map, int n)
{
	if (n + 3 < map->len - 1 && (n / 3) % map->col < map->col - 1)
	{
		draw_line(mlx, \
			(double []){map->matrix[n], map->matrix[n + 1]}, \
			(double []){map->matrix[n + 3], map->matrix[n + 4]}, \
			select_color(map, n, n + 3));
	}
	if (n + 3 < map->len - 1 && (n / 3) % map->col == map->col - 1)
	{
		draw_line(mlx, \
			(double []){map->matrix[n], map->matrix[n + 1]}, \
			(double []){map->matrix[n - map->col * 3 + 3], \
						map->matrix[n - map->col * 3 + 4]}, \
			select_color(map, n, n + 3));
	}
	if (map->issphere && ((n / 3) % map->col == 0))
	{
		draw_line(mlx, \
			(double []){map->matrix[n], map->matrix[n + 1]}, \
			(double []){map->matrix[n + map->col * 3 - 3], \
						map->matrix[n + map->col * 3 - 2]}, \
			select_color(map, n, map->col * 3 - 3));
	}
}

void	draw_vertical_line(t_mlx *mlx, t_map *map, int n)
{
	if (n + map->col * 3 < map->len - 1)
	{
		draw_line(mlx, \
			(double []){map->matrix[n], map->matrix[n + 1]}, \
			(double []){map->matrix[n + map->col * 3], \
						map->matrix[n + map->col * 3 + 1]}, \
			select_color(map, n, n + map->col * 3));
	}
}

void	draw_point(t_mlx *mlx, t_map *map, int n)
{
	ft_mlx_pixel_put(mlx->img, \
					map->matrix[n], \
					map->matrix[n + 1], \
					map->color[n / 3]);
}
