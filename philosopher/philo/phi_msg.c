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

#include "philosopher.h"

void	phi_perror(int errno)
{
	if (errno == NEGATIVE)
		printf("Number must be grater than 0\n");
	else if (errno == BAD_INPUT)
		printf("Input must be only numbers\n");
	else if (errno == OUT_OF_MAX)
		printf("Number must be less or equal than INT_MAX\n");
	else if (errno == MALLOC_FAIL)
		printf("Memory allocating failed\n");
	else if (errno == MUTEX_ERROR)
		printf("Mutex initialization faild\n");
	else
		printf("Unknown error\n");
}
