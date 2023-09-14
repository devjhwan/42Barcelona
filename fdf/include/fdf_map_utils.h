/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:49:25 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/14 20:49:27 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MAP_UTILS_H
# define FDF_MAP_UTILS_H

# include <math.h>
# include <stdlib.h>

# define QUATERNION_EPS 0.0001

typedef struct s_quaternion
{
	double	w;
	double	i;
	double	j;
	double	k;
}	t_quat;

void	quaternion_identity(t_quat *quaternion);
void	quaternion_copy(t_quat *q1, t_quat *q2);
int		quaternion_equal(t_quat	*q1, t_quat	*q2);
void	quaternion_from_axisangle(double axis[3], double angle, t_quat *output);
void	quaternion_conjugate(t_quat *q, t_quat *output);
double	quaternion_norm(t_quat *q);
void	quaternion_normalize(t_quat *q, t_quat *output);
void	quaternion_multiply(t_quat *q1, t_quat *q2, t_quat *output);
void	quaternion_rotate(t_quat *q, double v[3]);

void	rotate_matrix(double *matrix, int len, t_quat *quaternion);
void	scale_matrix(double *matrix, int len, double scale[3]);
void	translate_matrix(double *matrix, int len, double position[3]);
void	print_matrix(double *matrix, int row, int col);
void	free_matrix2d(void *matrix);
#endif
