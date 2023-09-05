/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:54:01 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/04 18:45:52 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MAP_H
# define FDF_MAP_H

# include <fcntl.h>
# include "libft.h"

# define GIGABYTE 1073741824
# define MEGABYTE 1048576
# define KILOBYTE 1024

typedef struct s_map
{
	int				row;
	int				col;
	int				**matrix;
	unsigned int	**color;
}	t_map;

t_map	*parse_fdf(char *fdf_file);
void	*get_matrix2d(size_t row, size_t col, size_t size);
void	free_matrix2d(void *matrix);

#endif
