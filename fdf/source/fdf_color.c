/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:18:20 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/15 13:18:23 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_color.h"

unsigned int	interpolate_color(double ratio, unsigned int color1, \
												unsigned int color2)
{
	unsigned char	rgb1[3];
	unsigned char	rgb2[3];
	unsigned char	result_rgb[3];

	rgb1[0] = (color1 >> 16) & 0xFF;
	rgb1[1] = (color1 >> 8) & 0xFF;
	rgb1[2] = color1 & 0xFF;
	rgb2[0] = (color2 >> 16) & 0xFF;
	rgb2[1] = (color2 >> 8) & 0xFF;
	rgb2[2] = color2 & 0xFF;
	result_rgb[0] = rgb1[0] + (rgb2[0] - rgb1[0]) * ratio;
	result_rgb[1] = rgb1[1] + (rgb2[1] - rgb1[1]) * ratio;
	result_rgb[2] = rgb1[2] + (rgb2[2] - rgb1[2]) * ratio;
	return (result_rgb[0] << 16 | result_rgb[1] << 8 | result_rgb[2]);
}

unsigned int	interpolate_color_world(double ratio, unsigned int *color)
{
	if (ratio < 0.3)
		return (interpolate_color(ratio / 0.3, color[0], color[1]));
	else if (ratio < 0.7)
		return (interpolate_color((ratio - 0.3) / 0.4, color[1], color[2]));
	else
		return (interpolate_color((ratio - 0.7) / 0.3, color[2], color[3]));
}

unsigned int	*gradient_between_point(unsigned int *color, int n1, int n2, \
										unsigned int result[2])
{
	result[0] = color[n1 / 3];
	result[1] = color[n2 / 3];
	return (result);
}

unsigned int	*gradient_by_zaxis(double min_max[2], int n_z[2], \
								unsigned int color[2], unsigned int result[2])
{
	double			range;
	double			ratio;

	range = min_max[1] - min_max[0];
	ratio = (n_z[0] - min_max[0]) / range;
	result[0] = interpolate_color(ratio, color[0], color[1]);
	ratio = (n_z[1] - min_max[0]) / range;
	result[1] = interpolate_color(ratio, color[0], color[1]);
	return (result);
}

unsigned int	*gradient_by_world(double min_max[2], int n_z[2], \
								unsigned int color[4], unsigned int result[2])
{
	double			range;
	double			ratio;

	range = min_max[1] - min_max[0];
	ratio = (n_z[0] - min_max[0]) / range;
	result[0] = interpolate_color_world(ratio, color);
	ratio = (n_z[1] - min_max[0]) / range;
	result[1] = interpolate_color_world(ratio, color);
	return (result);
}
