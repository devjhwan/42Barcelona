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

int	mouse_hook_function(int button, int x, int y, t_mlx *mlx)
{
	mlx = NULL;
	ft_printf("button: %d\nx: %d\ny: %d\n", button, x, y);
	ft_printf("\n");
	return (0);
}
