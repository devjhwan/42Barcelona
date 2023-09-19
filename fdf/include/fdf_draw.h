/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:07:21 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/15 13:07:22 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DRAW_H
# define FDF_DRAW_H

void			select_point(t_mlx *mlx, t_map *map, int n);
void			draw_shape(t_mlx *mlx, t_map *map);
void			ft_mlx_pixel_put(t_img *img, int x, int y, unsigned int color);
void			draw_line(t_mlx *mlx, double p[2], double q[2], \
							unsigned int *color);
void			draw_horitzontal_line(t_mlx *mlx, t_map *map, int n);
void			draw_vertical_line(t_mlx *mlx, t_map *map, int n);
void			draw_point(t_mlx *mlx, t_map *map, int n);
unsigned int	*select_color(t_map *map, int n1, int n2);
void			get_min_max(t_map *map, double *min, double *max);
#endif
