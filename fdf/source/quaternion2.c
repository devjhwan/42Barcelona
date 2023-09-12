/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 02:14:04 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/06 02:14:05 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"

double	quaternion_norm(t_quat *q)
{
	return (sqrt(q->w * q->w + q->i * q->i + q->j * q->j + q->k * q->k));
}

void	quaternion_normalize(t_quat *q, t_quat *output)
{
	double	len;
	t_quat	result;

	len = quaternion_norm(q);
	result.w = q->w / len;
	result.i = q->i / len;
	result.j = q->j / len;
	result.k = q->k / len;
	output->w = result.w;
	output->i = result.i;
	output->j = result.j;
	output->k = result.k;
}

void	quaternion_multiply(t_quat *q1, t_quat *q2, t_quat *output)
{
	t_quat	result;

	result.w = q1->w * q2->w - q1->i * q2->i - \
				q1->j * q2->j - q1->k * q2->k;
	result.i = q1->i * q2->w + q1->w * q2->i + \
				q1->j * q2->k - q1->k * q2->j;
	result.j = q1->w * q2->j - q1->i * q2->k + \
				q1->j * q2->w + q1->k * q2->i;
	result.k = q1->w * q2->k + q1->i * q2->j - \
				q1->j * q2->i + q1->k * q2->w;
	output->w = result.w;
	output->i = result.i;
	output->j = result.j;
	output->k = result.k;
}

typedef struct s_rotate
{
	double	ww;
	double	xx;
	double	yy;
	double	zz;
	double	wx;
	double	wy;
	double	wz;
	double	xy;
	double	xz;
	double	yz;
}	t_rotate;

void	quaternion_rotate(t_quat *q, double v[3])
{
	t_rotate	r;
	double		output[3];

	r.ww = q->w * q->w;
	r.xx = q->i * q->i;
	r.yy = q->j * q->j;
	r.zz = q->k * q->k;
	r.wx = q->w * q->i;
	r.wy = q->w * q->j;
	r.wz = q->w * q->k;
	r.xy = q->i * q->j;
	r.xz = q->i * q->k;
	r.yz = q->j * q->k;
	output[0] = r.ww * v[0] + 2 * r.wy * v[2] - 2 * r.wz * v[1] + \
				r.xx * v[0] + 2 * r.xy * v[1] + 2 * r.xz * v[2] - \
				r.zz * v[0] - r.yy * v[0];
	output[1] = 2 * r.xy * v[0] + r.yy * v[1] + 2 * r.yz * v[2] + \
				2 * r.wz * v[0] - r.zz * v[1] + r.ww * v[1] - \
				2 * r.wx * v[2] - r.xx * v[1];
	output[2] = 2 * r.xz * v[0] + 2 * r.yz * v[1] + r.zz * v[2] - \
				2 * r.wy * v[0] - r.yy * v[2] + 2 * r.wx * v[1] - \
				r.xx * v[2] + r.ww * v[2];
	v[0] = output[0];
	v[1] = output[1];
	v[2] = output[2];
}
