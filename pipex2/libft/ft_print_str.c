/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c.                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:27:07 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/05 13:59:22 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_str2(t_flag *flag, char *s, int slen, int width)
{
	char	*buff;

	buff = (char *)malloc(sizeof(char) * width);
	if (buff == NULL)
		return (-1);
	if (flag->f & MINUS)
	{
		ft_memcpy(buff, s, slen);
		ft_memset(&buff[slen], ' ', width - slen);
	}
	else
	{
		ft_memset(buff, ' ', width - slen);
		ft_memcpy(&buff[width - slen], s, slen);
	}
	return (ft_flush_buffer(buff, width));
}

int	ft_print_str(t_flag *flag, char *s)
{
	int	slen;
	int	width;

	if (s == NULL)
		s = "(null)";
	slen = ft_strlen(s);
	if (flag->f & PRECITION)
		slen = ft_min(flag->precition, slen);
	width = ft_max(slen, flag->width);
	return (ft_print_str2(flag, s, slen, width));
}
