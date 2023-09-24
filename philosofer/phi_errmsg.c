/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_errmsg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:35:51 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/24 22:35:53 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	negative_number(void)
{
	printf("Number must be grater than 0\n");
}

void	bad_input_format(void)
{
	printf("Input must be only numbers\n");
}

void	number_out_of_max_range(void)
{
	printf("Number must be less or equal than INT_MAX\n");
}
