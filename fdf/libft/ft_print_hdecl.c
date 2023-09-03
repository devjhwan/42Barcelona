/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hdecl.c.                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:37:46 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/05 19:17:29 by junghwle         ###   ########.fr       */
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

static int	ft_print_hdecl3(char *buff, t_flag *flag, unsigned int hl, t_pack p)
{
	if (!(flag->f & ZERO) && (flag->f & HASHTAG) && hl != 0)
	{
		ft_memcpy(&buff[p.i], "0x", 2);
		p.i += 2;
	}
	if (flag->f & PRECITION && flag->precition > 0)
	{
		ft_memset(&buff[p.i], '0', p.slen - p.nlen);
		p.i += p.slen - p.nlen;
	}
	if (flag->precition != 0 || hl != 0)
	{
		ft_setnbr_base(&buff[p.i], hl, "0123456789abcdef");
		p.i += p.nlen;
	}
	if (flag->f & MINUS)
		ft_memset(&buff[p.i], ' ', p.width - p.slen - p.count);
	return (ft_flush_buffer(buff, p.width));
}

static int	ft_print_hdecl2(t_flag *flag, unsigned int hl, t_pack p)
{
	char	*buff;

	buff = (char *)malloc(sizeof(char) * p.width);
	if (buff == NULL)
		return (-1);
	if (flag->f & SPACE)
		buff[p.i++] = ' ';
	if (flag->f & ZERO)
	{
		if (flag->f & HASHTAG && hl != 0)
		{
			ft_memcpy(&buff[p.i], "0x", 2);
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
	return (ft_print_hdecl3(buff, flag, hl, p));
}

int	ft_print_hdecl(t_flag *flag, unsigned int hl)
{
	t_pack	p;

	p.i = 0;
	p.count = 0;
	p.nlen = ft_nblen_base(hl, 16);
	p.slen = p.nlen;
	if (flag->precition == 0 && hl == 0)
		p.slen = 0;
	else if (flag->f & PRECITION)
		p.slen = ft_max(flag->precition, p.slen);
	if (flag->f & HASHTAG && hl != 0)
		p.count += 2;
	if (flag->f & SPACE && !(flag->f & HASHTAG))
		p.count++;
	p.width = ft_max(flag->width, p.slen + p.count);
	return (ft_print_hdecl2(flag, hl, p));
}
