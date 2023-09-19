/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:19:06 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/15 13:19:38 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_COLOR_H
# define FDF_COLOR_H

# define BLACK 0x000000
# define RED 0xFF0000
# define DEEPBLUE 0x00008B
# define GREEN 0x00FF00
# define WHITE 0xFFFFFF

# define BASIC_COLOR 0
# define BLACK_RED 1
# define DEEPBLUE_RED 2
# define BLACK_DEEPBLUE 3
# define WORLD 4
# define COLOR_SET_COUNT 5

unsigned int	interpolate_color(double ratio, unsigned int color1, \
												unsigned int color2);
unsigned int	interpolate_color_world(double ratio, unsigned int *color);
unsigned int	*gradient_between_point(unsigned int *color, int n1, int n2, \
										unsigned int result[2]);
unsigned int	*gradient_by_zaxis(double min_max[2], int n_z[2], \
								unsigned int color[2], unsigned int result[2]);
unsigned int	*gradient_by_world(double min_max[2], int n_z[2], \
								unsigned int color[4], unsigned int result[2]);

#endif
