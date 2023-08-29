/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flush_buffer.c.                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:25:08 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/05 13:51:18 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_flush_buffer(char *buff, int width)
{
	int	tmp;

	tmp = write(1, buff, width);
	free(buff);
	return (tmp);
}
