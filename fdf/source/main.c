/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:21:00 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/04 17:46:30 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_img	*init_img(void *mlx)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (img == NULL)
		return (NULL);
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (img->img == NULL)
	{
		free(img);
		return (NULL);
	}
	img->addr = mlx_get_data_addr(\
					img->img, \
					&img->bits_per_pixel, \
					&img->size_line, \
					&img->endian);
	if (img->addr == NULL)
	{
		mlx_destroy_image(mlx, img->img);
		free(img);
		return (NULL);
	}
	return (img);
}

static void	*mlx_initialize(t_mlx *mlx)
{
	ft_bzero(mlx, sizeof(t_mlx));
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		return (NULL);
	mlx->mlx_win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "junghwle's fdf");
	mlx->img = init_img(mlx->mlx);
	if (mlx->mlx_win == NULL || mlx->img == NULL)
	{
		free_mlx(mlx);
		return (NULL);
	}
	return (mlx);
}

void	fdf_start(t_mlx *mlx, t_map *map, t_fdf_flag *flag, char *fdf_filename)
{
	if (mlx_initialize(mlx) == NULL)
		exit(EXIT_FAILURE);
	if (map_initialize(map, fdf_filename) == NULL)
	{
		free_mlx(mlx);
		exit(EXIT_FAILURE);
	}
	ft_bzero(flag, sizeof(t_fdf_flag));
	draw_shape(mlx, map);
}

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_map		map;
	t_fdf_flag	flag;

	if (argc != 2)
		return (0);
	fdf_start(&mlx, &map, &flag, argv[1]);
	mlx_hook(mlx.mlx_win, ON_KEYDOWN, KEY_PRESS, \
			key_press_hook, (void *[]){&mlx, &map, &flag});
	mlx_hook(mlx.mlx_win, ON_KEYUP, KEY_RELEASE, \
			key_release_hook, (void *[]){&mlx, &map, &flag});
	mlx_hook(mlx.mlx_win, ON_MOUSEDOWN, BUTTON_PRESS, \
			mouse_press_function, (void *[]){&mlx, &map, &flag});
	//mlx_hook(mlx.mlx_win, ON_MOUSEMOVE, NO_MASK, \
	//		mouse_move_function, (void *[]){&mlx, &map, &flag});
	//mlx_hook(mlx.mlx_win, ON_MOUSEUP, BUTTON_RELEASE, \
	//		mouse_up_function, (void *[]){&mlx, &map, &flag});
	mlx_hook(mlx.mlx_win, ON_DESTROY, NO_MASK, \
			clear_program, (void *[]){&mlx, &map, &flag});
	mlx_loop_hook(mlx.mlx, render_frame_hook, \
			(void *[]){&mlx, &map, &flag});
	mlx_loop(mlx.mlx);
}
