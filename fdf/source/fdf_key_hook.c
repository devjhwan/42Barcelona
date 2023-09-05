/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:54:10 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/04 17:04:42 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	call_exit(int keycode, t_mlx *mlx)
{
	ft_printf("%d\n", keycode);
	if (keycode == KEY_EXIT)
	{
		free_mlx(*mlx);
		exit(0);
	}
}

int	key_hook_function(int keycode, t_mlx *mlx)
{
	call_exit(keycode, mlx);
	return (0);
}
