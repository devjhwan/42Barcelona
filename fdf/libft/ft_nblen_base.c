/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen_base.c.                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:57:54 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/05 18:32:20 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nblen_base(size_t nb, size_t baselen)
{
	int	len;

	len = 1;
	while (nb >= baselen)
	{
		nb /= baselen;
		len++;
	}
	return (len);
}
