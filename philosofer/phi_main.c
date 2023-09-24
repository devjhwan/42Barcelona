/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:41:57 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/24 20:41:58 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofer.h"

int	check_arg(int argc, char **argv)
{
	int	i;
	int	num;

	if (argc < 5 || argc > 6)
	{
		printf("number_of_philosophers time_to_die time_to_eat time_to_sleep");
		printf(" [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	i = 1;
	while (argv[i] != NULL)
	{
		if (phi_atoi((const char *)argv[i], &num) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (check_arg(argc, argv) == 1)
		return (0);
}
