/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:47:26 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/04 17:45:16 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HOOK_H
# define FDF_HOOK_H

typedef struct s_fdf_flag
{
	unsigned char	key;
	unsigned char	arrow;
	unsigned char	mouse;
}	t_fdf_flag;
typedef unsigned short int	t_byte;

int	key_press_hook(int keycode, void *fdf_pack[3]);
int	key_release_hook(int keycode, void *fdf_pack[3]);
int	mouse_press_function(int button, int x, int y, void *fdf_pack[3]);
int	render_frame_hook(void *fdf_pack[3]);

/*KEY EVENTS*/
# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_DESTROY 17

/*KEY EVENT MASKS*/
# define NO_MASK 0
# define KEY_PRESS 1
# define KEY_RELEASE 2
# define BUTTON_PRESS 4
# define BUTTON_RELEASE 8

/*FLAG*/
# define FLAG_T 1
# define FLAG_R 2
# define FLAG_S 4
# define FLAG_X 8
# define FLAG_Y 16
# define FLAG_Z 32
# define FLAG_Q 64
# define FLAG_H 128
# define FLAG_UP 1
# define FLAG_DOWN 2
# define FLAG_LEFT 4
# define FLAG_RIGHT 8
# define FLAG_LEFT_MOUSE 1
# define FLAG_RIGHT_MOUSE 2

/*LINUX KEY CODES*/
# define KEY_T 116
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_EXIT 65307
# define KEY_S 115
# define KEY_X 120
# define KEY_Y 121
# define KEY_Z 122
# define KEY_R 114
# define KEY_Q 113
# define KEY_H 104

/*MAC KEY CODES*/

/*
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_T 17
# define KEY_Y 16
# define KEY_U 32
# define KEY_I 34
# define KEY_O 31
# define KEY_P 35
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_G 5
# define KEY_H 4
# define KEY_J 38
# define KEY_K 40
# define KEY_L 37
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_N 45
# define KEY_M 46
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_5 23
# define KEY_6 22
# define KEY_7 26
# define KEY_8 28
# define KEY_9 25
# define KEY_0 29
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_EXIT 53
*/

#endif
