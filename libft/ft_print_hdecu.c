/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hdecu.c.                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:38:29 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/06 14:04:36 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_pack
{
	int		nlen;
	int		slen;
	int		width;
	int		count;
	int		i;
}	t_pack;

static int	ft_print_hdecu3(char *buff, t_flag *flag, unsigned int hu, t_pack p)
{
	if (!(flag->f & ZERO) && flag->f & HASHTAG && hu != 0)
	{
		ft_memcpy(&buff[p.i], "0X", 2);
		p.i += 2;
	}
	if (flag->f & PRECITION && flag->precition > 0)
	{
		ft_memset(&buff[p.i], '0', p.slen - p.nlen);
		p.i += p.slen - p.nlen;
	}
	if (flag->precition != 0 || hu != 0)
	{
		ft_setnbr_base(&buff[p.i], hu, "0123456789ABCDEF");
		p.i += p.nlen;
	}
	if (flag->f & MINUS)
		ft_memset(&buff[p.i], ' ', p.width - p.slen - p.count);
	return (ft_flush_buffer(buff, p.width));
}

static int	ft_print_hdecu2(t_flag *flag, unsigned int hu, t_pack p)
{
	char	*buff;

	buff = (char *)malloc(sizeof(char) * p.width);
	if (buff == NULL)
		return (-1);
	if (flag->f & SPACE)
		buff[p.i++] = ' ';
	if (flag->f & ZERO)
	{
		if (flag->f & HASHTAG && hu != 0)
		{
			ft_memcpy(&buff[p.i], "0X", 2);
			p.i += 2;
		}
		ft_memset(&buff[p.i], '0', p.width - p.slen - p.count);
		p.i += p.width - p.slen - p.count;
	}
	else if (!(flag->f & MINUS))
	{
		ft_memset(&buff[p.i], ' ', p.width - p.slen - p.count);
		p.i += p.width - p.slen - p.count;
	}
	return (ft_print_hdecu3(buff, flag, hu, p));
}

int	ft_print_hdecu(t_flag *flag, unsigned int hu)
{
	t_pack	p;

	p.i = 0;
	p.count = 0;
	p.nlen = ft_nblen_base(hu, 16);
	p.slen = p.nlen;
	if (flag->precition == 0 && hu == 0)
		p.slen = 0;
	else if (flag->f & PRECITION)
		p.slen = ft_max(flag->precition, p.slen);
	if (flag->f & HASHTAG && hu != 0)
		p.count += 2;
	if (flag->f & SPACE && !(flag->f & HASHTAG))
		p.count++;
	p.width = ft_max(flag->width, p.slen + p.count);
	return (ft_print_hdecu2(flag, hu, p));
}
