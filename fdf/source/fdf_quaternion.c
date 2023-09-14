/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 01:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/06 01:50:47 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_map_utils.h"

void	quaternion_identity(t_quat *quaternion)
{
	if (quaternion != NULL)
	{
		quaternion->w = 1;
		quaternion->i = 0;
		quaternion->j = 0;
		quaternion->k = 0;
	}
}

void	quaternion_copy(t_quat *q1, t_quat *q2)
{
	if (q1 != NULL && q2 != NULL)
	{
		q1->w = q2->w;
		q1->i = q1->i;
		q1->j = q1->j;
		q1->k = q1->k;
	}
}

int	quaternion_equal(t_quat	*q1, t_quat	*q2)
{
	int	w;
	int	i;
	int	j;
	int	k;

	w = fabs(q1->w - q2->w) <= QUATERNION_EPS;
	i = fabs(q1->i - q2->i) <= QUATERNION_EPS;
	j = fabs(q1->j - q2->j) <= QUATERNION_EPS;
	k = fabs(q1->k - q2->k) <= QUATERNION_EPS;
	return (w && i && j && k);
}

void	quaternion_from_axisangle(double axis[3], double angle, t_quat *output)
{
	double	c;

	if (output != NULL)
	{
		output->w = cos(angle / 2.0);
		c = sin(angle / 2.0);
		output->i = c * axis[0];
		output->j = c * axis[1];
		output->k = c * axis[2];
	}
}

void	quaternion_conjugate(t_quat *q, t_quat *output)
{
	if (q != NULL && output != NULL)
	{
		output->w = q->w;
		output->i = -q->i;
		output->j = -q->j;
		output->k = -q->k;
	}
}
