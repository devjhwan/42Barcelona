/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_udec.c.                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:37:28 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/05 19:08:56 by junghwle         ###   ########.fr       */
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

static int	ft_print_udec3(char *buff, t_flag *flag, unsigned int u, t_pack p)
{
	if (flag->f & PRECITION && flag->precition > 0)
	{
		ft_memset(&buff[p.i], '0', p.slen - p.nlen);
		p.i += p.slen - p.nlen;
	}
	if (flag->precition != 0 || u != 0)
	{
		ft_setnbr_base(&buff[p.i], u, "0123456789");
		p.i += p.nlen;
	}
	if (flag->f & MINUS)
		ft_memset(&buff[p.i], ' ', p.width - p.slen - p.count);
	return (ft_flush_buffer(buff, p.width));
}

static int	ft_print_udec2(t_flag *flag, unsigned int u, t_pack p)
{
	char	*buff;

	buff = (char *)malloc(sizeof(char) * p.width);
	if (buff == NULL)
		return (-1);
	if (flag->f & SPACE)
		buff[p.i++] = ' ';
	if (flag->f & ZERO)
	{
		ft_memset(&buff[p.i], '0', p.width - p.slen - p.count);
		p.i += p.width - p.slen - p.count;
	}
	else if (!(flag->f & MINUS))
	{
		ft_memset(&buff[p.i], ' ', p.width - p.slen - p.count);
		p.i += p.width - p.slen - p.count;
	}
	return (ft_print_udec3(buff, flag, u, p));
}

int	ft_print_udec(t_flag *flag, unsigned int u)
{
	t_pack	p;

	p.i = 0;
	p.count = 0;
	p.nlen = ft_nblen_base(u, 10);
	p.slen = p.nlen;
	if (flag->precition == 0 && u == 0)
		p.slen = 0;
	else if (flag->f & PRECITION)
		p.slen = ft_max(flag->precition, p.slen);
	if (flag->f & SPACE)
		p.count++;
	p.width = ft_max(flag->width, p.slen + p.count);
	return (ft_print_udec2(flag, u, p));
}
