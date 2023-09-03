/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c.                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:36:04 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/05 16:59:04 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_ptr(t_flag *flag, size_t p)
{
	int		slen;
	int		width;
	char	*buff;

	slen = ft_nblen_base(p, 16);
	width = ft_max(flag->width, slen + 2);
	buff = (char *)malloc(sizeof(char) * width);
	if (buff == NULL)
		return (-1);
	if (flag->f & MINUS)
	{
		ft_memcpy(buff, "0x", 2);
		ft_setnbr_base(&buff[2], p, "0123456789abcdef");
		ft_memset(&buff[slen + 2], ' ', width - slen - 2);
	}
	else
	{
		ft_memset(buff, ' ', width - slen - 2);
		ft_memcpy(&buff[width - slen - 2], "0x", 2);
		ft_setnbr_base(&buff[width - slen], p, "0123456789abcdef");
	}
	return (ft_flush_buffer(buff, width));
}
