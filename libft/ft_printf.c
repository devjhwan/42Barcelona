/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c.                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:11:08 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/05 13:52:13 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;
	int		tmp;

	va_start(ap, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			tmp = ft_putchar(str[i]);
		else
			tmp = ft_print_format(str, &i, ap);
		if (tmp < 0)
			return (-1);
		count += tmp;
		i++;
	}
	va_end(ap);
	return (count);
}
