/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:23:54 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/04 17:05:07 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_mlx(t_mlx *mlx)
{
	if (mlx->mlx_win != NULL)
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	if (mlx->img != NULL)
		mlx_destroy_image(mlx->mlx, mlx->img->img);
}

void	free_map(t_map *map)
{
	free(map->matrix);
	map->matrix = NULL;
	free(map->color);
	map->color = NULL;
	free(map->m_copy);
	map->m_copy = NULL;
}

int	clear_program(void *fdf_pack[3])
{
	t_mlx	*mlx;
	t_map	*map;

	mlx = (t_mlx *)fdf_pack[0];
	map = (t_map *)fdf_pack[1];
	free_map(map);
	free_mlx(mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
