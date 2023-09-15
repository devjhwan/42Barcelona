/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_loop_hook.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:14:35 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/15 13:14:36 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_LOOP_HOOK_H
# define FDF_LOOP_HOOK_H

void	back_to_original_shape(t_mlx *mlx, t_map *map, t_fdf_flag *flag);
void	set_to_spherical_perspective(t_mlx *mlx, t_map *map, t_fdf_flag *flag);
int		render_frame_hook(void *fdf_pack[3]);

void	translate_keyboard(t_mlx *mlx, t_map *map, t_fdf_flag *flag);
void	scale_keyboard(t_mlx *mlx, t_map *map, t_fdf_flag *flag);
void	rotate_keyboard(t_mlx *mlx, t_map *map, t_fdf_flag *flag);

void	translate_mouse(t_mlx *mlx, t_map *map, t_fdf_flag *flag);
void	scale_mouse(t_mlx *mlx, t_map *map, t_fdf_flag *flag);
void	rotate_mouse(t_mlx *mlx, t_map *map, t_fdf_flag *flag);

#endif
