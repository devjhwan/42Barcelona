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

static void	press_arrow(int keycode, t_fdf_flag *flag)
{
	if (keycode == KEY_UP)
		flag->arrow |= FLAG_UP;
	if (keycode == KEY_DOWN)
		flag->arrow |= FLAG_DOWN;
	if (keycode == KEY_LEFT)
		flag->arrow |= FLAG_LEFT;
	if (keycode == KEY_RIGHT)
		flag->arrow |= FLAG_RIGHT;
}

static void	release_arrow(int keycode, t_fdf_flag *flag)
{
	if (keycode == KEY_UP)
		flag->arrow &= ~FLAG_UP;
	if (keycode == KEY_DOWN)
		flag->arrow &= ~FLAG_DOWN;
	if (keycode == KEY_LEFT)
		flag->arrow &= ~FLAG_LEFT;
	if (keycode == KEY_RIGHT)
		flag->arrow &= ~FLAG_RIGHT;
}

static void	call_exit(int keycode, void *fdf_pack[3])
{
	if (keycode == KEY_EXIT)
		clear_program(fdf_pack);
}

int	key_press_hook(int keycode, void *fdf_pack[3])
{
	t_fdf_flag	*flag;

	flag = (t_fdf_flag *)fdf_pack[2];
	call_exit(keycode, fdf_pack);
	if (keycode == KEY_T)
		flag->key = FLAG_T;
	if (keycode == KEY_S)
		flag->key = FLAG_S;
	if (flag->key & FLAG_S && keycode == KEY_X)
		flag->key ^= FLAG_X;
	if (flag->key & FLAG_S && keycode == KEY_Y)
		flag->key ^= FLAG_Y;
	if (flag->key & FLAG_S && keycode == KEY_Z)
		flag->key ^= FLAG_Z;
	if (keycode == KEY_R)
		flag->key = FLAG_R;
	press_arrow(keycode, flag);
	ft_printf("%x\n", flag->key);
	return (0);
}

int	key_release_hook(int keycode, void *fdf_pack[3])
{
	release_arrow(keycode, (t_fdf_flag *)fdf_pack[2]);
	return (0);
}
