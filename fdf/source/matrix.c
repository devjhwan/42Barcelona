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

#include <stdlib.h>

void	*get_matrix2d(size_t row, size_t col, size_t size)
{
	void	**matrix;
	size_t	i;

	matrix = malloc(sizeof(void **) * (row + 1));
	if (matrix == NULL)
		return (NULL);
	i = 0;
	while (i < row)
	{
		matrix[i] = calloc(col, size);
		if (matrix[i] == NULL)
		{
			while (i > 0)
				free(matrix[--i]);
			return (free(matrix), NULL);
		}
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
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