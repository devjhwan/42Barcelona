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
	img->addr = mlx_get_data_addr(			\
					img->img,				\
					&img->bits_per_pixel,	\
					&img->size_line,		\
					&img->endian);
	if (img->addr == NULL)
	{
		mlx_destroy_image(mlx, img->img);
		free(img);
		return (NULL);
	}
	return (img);
}

static void	mlx_struct_init(t_mlx *mlx, char *fdf_file)
{
	ft_bzero(mlx, sizeof(t_mlx));
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		exit(EXIT_FAILURE);
	mlx->mlx_win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "junghwle's fdf");
	mlx->img = init_img(mlx->mlx);
	mlx->tmp_img = init_img(mlx->mlx);
	mlx->map = parse_fdf(fdf_file);
	if (mlx->mlx_win == NULL || mlx->img == NULL || \
		mlx->tmp_img == NULL || mlx->map == NULL)
	{
		free_mlx(*mlx);
		exit(EXIT_FAILURE);
	}
}

static int	mlx_clear_function(t_mlx *mlx)
{
	free_mlx(*mlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		return (0);
	mlx_struct_init(&mlx, argv[1]);
	mlx_hook(mlx.mlx_win, ON_KEYDOWN, KEY_PRESS, \
			key_hook_function, &mlx);
	mlx_hook(mlx.mlx_win, ON_MOUSEDOWN, BUTTON_PRESS, \
			mouse_hook_function, &mlx);
	mlx_hook(mlx.mlx_win, ON_DESTROY, NO_MASK, \
			mlx_clear_function, &mlx);
	mlx_loop(mlx.mlx);
}
