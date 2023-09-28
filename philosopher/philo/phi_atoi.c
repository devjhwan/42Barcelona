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

#include "philosopher.h"

static int	phi_isspace(const char c)
{
	return ((c >= 9 && c <= 13) || (c == 32));
}

static int	phi_isdigit(const char c)
{
	return (c >= '0' && c <= '9');
}

static int	final_check(const char c, const size_t tmp)
{
	if (!phi_isdigit(c) && c != '\0')
		return (phi_perror(BAD_INPUT), 1);
	if (tmp == 0)
		return (phi_perror(NEGATIVE), 1);
	if (tmp > INT_MAX)
		return (phi_perror(OUT_OF_MAX), 1);
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
		return (phi_perror(NEGATIVE), 1);
	i = 0;
	tmp = 0;
	while (phi_isdigit(str[i]) && tmp <= INT_MAX)
		tmp = tmp * 10 + str[i++] - '0';
	*num = tmp;
	return (final_check(str[i], tmp));
}
