/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:08:18 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/04 17:11:43 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_press_function(int button, int x, int y, void *fdf_pack[3])
{
	/*
	t_mlx	*mlx;
	t_map	*map;

	mlx = (t_mlx *)fdf_pack[0];
	map = (t_map *)fdf_pack[1];
	*/
	if (fdf_pack)
		fdf_pack = NULL;
	ft_printf("button: %d\nx: %d\ny: %d\n", button, x, y);
	ft_printf("\n");
	return (0);
}
