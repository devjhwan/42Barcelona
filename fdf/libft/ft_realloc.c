/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 00:22:47 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/17 17:43:27 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *p, size_t oldsize, size_t newsize)
{
	char	*s;
	char	*_p;
	size_t	i;

	if (p == NULL)
		return (NULL);
	s = (char *)malloc(sizeof(char) * newsize);
	if (s == NULL)
		return (NULL);
	_p = (char *)p;
	i = 0;
	while (i < oldsize)
	{
		s[i] = _p[i];
		i++;
	}
	return (s);
}
