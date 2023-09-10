/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:47:57 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/04 19:04:25 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_map.h"

void	translate_matrix(t_map *map, double position[3])
{
	int	n;

	n = 0;
	while (n < map->len)
	{
		map->matrix[n] += position[0];
		map->matrix[n + 1] += position[1];
		map->matrix[n + 2] += position[2];
		n += 3;
	}
}

void	scale_matrix(t_map *map, double scale[3])
{
	int		n;

	n = 0;
	while (n < map->len)
	{
		map->matrix[n] *= scale[0];
		map->matrix[n + 1] *= scale[1];
		map->matrix[n + 2] *= scale[2];
		n += 3;
	}
}

void	rotate_matrix(t_map *map, t_quat *quaternion)
{
	int		n;

	n = 0;
	while (n < map->len)
	{
		quaternion_rotate(quaternion, &map->matrix[n]);
		n += 3;
	}
}

void	print_matrix(t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i++ < map->row)
	{
		j = 0;
		while (j++ < map->col)
		{
			ft_printf("%d ", (int)map->matrix[k + 2]);
			k += 3;
		}
		ft_printf("\n");
	}
}

void	free_matrix2d(void *matrix)
{
	void	**mat;
	int		i;

	if (matrix != NULL)
	{
		mat = (void **)matrix;
		i = 0;
		while (mat[i] != NULL)
			free(mat[i++]);
		free(mat);
	}
}
