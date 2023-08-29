/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c.                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:20:34 by junghwle          #+#    #+#             */
/*   Updated: 2023/06/06 18:04:24 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_init_flag(t_flag *flag)
{
	flag->f = 0;
	flag->width = 0;
	flag->precition = -1;
	flag->conversion = 0;
}

static void	ft_parse_flag(const char *str, int *i, t_flag *flag)
{
	(*i)++;
	while ((str[*i] != 0) && ((ft_strchr("#-+ 0", str[*i]) != NULL) \
			|| (ft_isdigit(str[*i]))))
	{
		if (str[*i] == '#')
			flag->f |= HASHTAG;
		else if (str[*i] == '-')
			flag->f |= MINUS;
		else if (str[*i] == '+')
			flag->f |= PLUS;
		else if (str[*i] == ' ')
			flag->f |= SPACE;
		else if (str[*i] == '0')
			flag->f |= ZERO;
		else
		{
			flag->width = ft_atoi(&str[*i]);
			while (ft_isdigit(str[(*i) + 1]))
				(*i)++;
		}
		(*i)++;
	}
	if (flag->f & MINUS)
		flag->f &= ~ZERO;
}

static void	ft_parse_precition(const char *str, int *i, t_flag *flag)
{
	if (str[*i] == '.')
	{
		(*i)++;
		flag->f |= PRECITION;
		flag->precition = ft_atoi(&str[*i]);
		while (ft_isdigit(str[*i]))
			(*i)++;
		flag->f &= ~ZERO;
	}
}

static void	ft_parse_conversion(const char *str, int *i, t_flag *flag)
{
	flag->conversion = str[*i];
}

int	ft_print_format(const char *str, int *i, va_list ap)
{
	t_flag	flag;

	ft_init_flag(&flag);
	ft_parse_flag(str, i, &flag);
	ft_parse_precition(str, i, &flag);
	ft_parse_conversion(str, i, &flag);
	ft_parse_conversion(str, i, &flag);
	return (ft_print_conversion(&flag, ap));
}
