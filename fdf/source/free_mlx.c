/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:23:54 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/04 17:05:07 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_mlx(t_mlx mlx)
{
	if (mlx.mlx != NULL)
	{
		if (mlx.mlx_win != NULL)
			mlx_destroy_window(mlx.mlx, mlx.mlx_win);
		if (mlx.img != NULL)
			mlx_destroy_image(mlx.mlx, mlx.img->img);
		if (mlx.tmp_img != NULL)
			mlx_destroy_image(mlx.mlx, mlx.tmp_img->img);
		if (mlx.map != NULL)
		{
			free_matrix2d(mlx.map->matrix);
			free_matrix2d(mlx.map->color);
			free(mlx.map);
		}
	}
}
