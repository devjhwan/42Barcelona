/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion.c.                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:55:30 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/05 13:51:47 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_conversion(t_flag *flag, va_list ap)
{
	char	ch;

	ch = flag->conversion;
	if (ch == 'c')
		return (ft_print_char(flag, va_arg(ap, int)));
	else if (ch == 's')
		return (ft_print_str(flag, va_arg(ap, char *)));
	else if (ch == 'p')
		return (ft_print_ptr(flag, va_arg(ap, size_t)));
	else if (ch == 'd' || ch == 'i')
		return (ft_print_dec(flag, va_arg(ap, int)));
	else if (ch == 'u')
		return (ft_print_udec(flag, va_arg(ap, unsigned int)));
	else if (ch == 'x')
		return (ft_print_hdecl(flag, va_arg(ap, unsigned int)));
	else if (ch == 'X')
		return (ft_print_hdecu(flag, va_arg(ap, unsigned int)));
	else if (ch == '%')
		return (ft_print_char(flag, '%'));
	else
		return (-1);
}
