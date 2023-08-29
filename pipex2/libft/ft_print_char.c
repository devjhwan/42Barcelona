/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c.                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:26:55 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/06 13:57:07 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(t_flag *flag, char c)
{
	int		width;
	char	*buff;

	width = ft_max(flag->width, 1);
	if (width == 1)
		return (ft_putchar(c));
	buff = (char *)malloc(sizeof(char) * width);
	if (buff == NULL)
		return (-1);
	if (flag->f & MINUS)
	{
		buff[0] = c;
		ft_memset(&buff[1], ' ', width - 1);
	}
	else
	{
		ft_memset(buff, ' ', width - 1);
		buff[width - 1] = c;
	}
	return (ft_flush_buffer(buff, width));
}
