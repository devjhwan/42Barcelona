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

int	mouse_press_function(int button, int x, int y, void *fdf_flag)
{
	t_fdf_flag	*flag;

	flag = (t_fdf_flag *)fdf_flag;
	if (button == MOUSE_LEFT)
		flag->mouse = FLAG_LEFT_MOUSE;
	else if (button == MOUSE_RIGHT)
		flag->mouse = FLAG_RIGHT_MOUSE;
	else if (button == MOUSE_SCROLL_DOWN)
		flag->mouse = FLAG_SCROLL_DOWN;
	else if (button == MOUSE_SCROLL_UP)
		flag->mouse = FLAG_SCROLL_UP;
	x = y;
	ft_printf("%d\n", flag->mouse);
	return (0);
}

int	mouse_move_function(int x, int y, void *fdf_flag)
{
	static int	prev_x;
	static int	prev_y;
	static int	v[2];
	t_fdf_flag	*flag;

	v[0] = x - prev_x;
	v[1] = y - prev_y;
	prev_x = x;
	prev_y = y;
	flag = (t_fdf_flag *)fdf_flag;
	if (flag->mouse & (FLAG_LEFT_MOUSE | FLAG_RIGHT_MOUSE))
	{
		flag->mouse_v[0] = v[0];
		flag->mouse_v[1] = v[1];
	}
	return (0);
}

int	mouse_release_function(int button, int x, int y, void *fdf_flag)
{
	t_fdf_flag	*flag;

	flag = (t_fdf_flag *)fdf_flag;
	if (button == MOUSE_LEFT)
		flag->mouse &= ~FLAG_LEFT_MOUSE;
	else if (button == MOUSE_RIGHT)
		flag->mouse &= ~FLAG_RIGHT_MOUSE;
	x = y;
	return (0);
}
