/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:29:00 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 11:59:12 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dptr;
	unsigned char	*sptr;

	dptr = (unsigned char *)dst;
	sptr = (unsigned char *)src;
	if (sptr >= dptr)
	{
		i = 0;
		while (i < len)
		{
			dptr[i] = sptr[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i-- > 0)
			dptr[i] = sptr[i];
	}
	return (dst);
}
