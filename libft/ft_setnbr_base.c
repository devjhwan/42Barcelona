/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:20:05 by junghwle          #+#    #+#             */
/*   Updated: 2023/08/29 23:35:58 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_setnbr_pack
{
	char	*buff;
	char	*base;
	size_t	blen;
}	t_setnbr_pack;

static void	ft_setnbr_base_rec(size_t nb, t_setnbr_pack p, int *i)
{
	if (nb >= p.blen)
		ft_setnbr_base_rec(nb / p.blen, p, i);
	else
		p.buff[(*i)++] = p.base[nb % p.blen];
}

void	ft_setnbr_base(char *buff, size_t nb, char *base)
{
	t_setnbr_pack	p;
	int				i;

	p.buff = buff;
	p.base = base;
	p.blen = ft_strlen(base);
	i = 0;
	ft_setnbr_base_rec(nb, p, &i);
}
