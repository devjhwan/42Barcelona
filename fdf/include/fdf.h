/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:23:15 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/04 17:10:14 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "fdf_hook.h"
# include "fdf_map.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_img		*img;
}	t_mlx;

void	draw_shape(t_mlx *mlx, t_map *map);
void	free_mlx(t_mlx *mlx);
int		clear_program(void *fdf_pack[3]);

#endif
