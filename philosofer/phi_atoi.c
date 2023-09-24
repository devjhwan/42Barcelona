/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:04:20 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 11:51:00 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofer.h"

static int	phi_isspace(const char c)
{
	return ((c >= 9 && c <= 13) || (c == 32));
}

static int	final_check(const char c, const size_t tmp)
{
	if (!phi_isdigit(c) && c != '\0')
		return (bad_input_format(), 1);
	if (tmp == 0)
		return (negative_number(), 1);
	if (tmp > INT_MAX)
		return (number_out_of_max_range(), 1);
	return (0);
}

int	phi_atoi(const char *str, int *num)
{
	int		i;
	int		sign;
	size_t	tmp;

	sign = 1;
	while (phi_isspace(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (sign == -1)
		return (negative_number(), 1);
	i = 0;
	tmp = 0;
	while (phi_isdigit(str[i]) && tmp <= INT_MAX)
		tmp = tmp * 10 + str[i++] - '0';
	*num = tmp;
	return (final_check(str[i], tmp));
}
