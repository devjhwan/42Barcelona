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

void	translate_matrix(double *matrix, int len, double position[3])
{
	int	n;

	n = 0;
	while (n < len)
	{
		matrix[n] += position[0];
		matrix[n + 1] += position[1];
		matrix[n + 2] += position[2];
		n += 3;
	}
}

void	scale_matrix(double *matrix, int len, double scale[3])
{
	int		n;

	n = 0;
	while (n < len)
	{
		matrix[n] *= scale[0];
		matrix[n + 1] *= scale[1];
		matrix[n + 2] *= scale[2];
		n += 3;
	}
}

void	rotate_matrix(double *matrix, int len, t_quat *quaternion)
{
	int		n;

	n = 0;
	while (n < len)
	{
		quaternion_rotate(quaternion, &matrix[n]);
		n += 3;
	}
}

void	print_matrix(double *matrix, int row, int col)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i++ < row)
	{
		j = 0;
		while (j++ < col)
		{
			ft_printf("%d ", (int)matrix[k + 2]);
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
