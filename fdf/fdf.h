/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:23:15 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/03 21:31:55 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_img;

typedef struct	s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_img	*img;
	t_img	*tmp_img;
}				t_mlx;

void	free_mlx(t_mlx mlx);

#endif
