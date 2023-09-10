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

static void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	x += WIDTH / 2;
	y += HEIGHT / 2;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	draw_line(t_mlx *mlx, double p[2], double q[2], \
				unsigned int color)
{
	double	v[2];
	double	v_n;

	v[0] = q[0] - p[0];
	v[1] = q[1] - p[1];
	v_n = sqrt(v[0] * v[0] + v[1] * v[1]);
	v[0] /= v_n;
	v[1] /= v_n;
	while (fabs(p[0] - q[0]) > 0.5 || fabs(p[1] - q[1]) > 0.5)
	{
		ft_mlx_pixel_put(mlx->img, (int)p[0], (int)p[1], color);
		p[0] += v[0];
		p[1] += v[1];
	}
	ft_mlx_pixel_put(mlx->img, (int)q[0], (int)q[1], color);
}

static void	mlx_clear_img(t_img *img)
{
	int	x;
	int	y;
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

void	draw_shape(t_mlx *mlx, t_map *map)
{
	int		n;

	mlx_clear_img(mlx->img);
	mlx_clear_window(mlx->mlx, mlx->mlx_win);
	n = 0;
	while (n < map->len)
	{
		if (n + 3 < map->len - 1 && (n / 3) % map->col < map->col - 1)
		{
			draw_line(mlx, \
				(double []){map->matrix[n] + map->transform.position[0], map->matrix[n + 1] + map->transform.position[1]}, \
				(double []){map->matrix[n + 3] + map->transform.position[0], map->matrix[n + 4] + map->transform.position[1]}, \
				map->color[n / 3]);
		}
		if (n + map->col * 3 < map->len - 1)
		{
			draw_line(mlx, \
				(double []){map->matrix[n] + map->transform.position[0], map->matrix[n + 1] + map->transform.position[1]}, \
				(double []){map->matrix[n + map->col * 3] + map->transform.position[0], \
					map->matrix[n + map->col * 3 + 1] + map->transform.position[1]}, \
				map->color[n / 3]);
		}
		n += 3;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img->img, 0, 0);
}