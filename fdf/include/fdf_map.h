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

# define WIDTH 1920
# define HEIGHT 1080

# include <fcntl.h>
# include "libft.h"
# include "fdf_map_utils.h"

# define GIGABYTE 1073741824
# define MEGABYTE 1048576
# define KILOBYTE 1024

# define WHITE 0x00FFFFFF

typedef struct s_transform
{
	double	position[3];
	double	scale[3];
	t_quat	quaternion;
}	t_transform;

typedef struct s_map
{
	int				row;
	int				col;
	int				len;
	double			*matrix;
	double			*m_copy;
	unsigned int	*color;
	unsigned int	*c_copy;
	int				issphere;
	t_transform		transform;
}	t_map;

void	*map_initialize(t_map *map, char *fdf_filename);
void	free_map(t_map *map);
double	get_middle_distance(t_map *map, int axis);
double	get_range(t_map *map, int axis);
void	shape_initialize(t_map *map);
void	reshape(t_map *map);
void	plane3d_to_sphere(t_map *map);
void	set_spherical_perspective(t_map *map);
#endif
