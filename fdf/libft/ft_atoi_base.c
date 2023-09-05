/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:04:20 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 11:51:00 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char c)
{
	return ((c >= 9 && c <= 13) || (c == 32));
}

unsigned int	ft_atoi_base(const char *str, const char *base)
{
	unsigned int	num;
	int				blen;

	num = 0;
	blen = ft_strlen(base);
	while (ft_isspace(*str) && (*str != '\0'))
		str++;
	ft_strchr(base, *str);
	while (ft_strchr(base, *str) != NULL && *str != '\0')
		num = num * blen + ft_strchr(base, *str++) - base;
	return (num);
}
