/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:10:41 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/28 14:10:42 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <string.h>

int	check_arg(int argc, char **argv, int *info_arr)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf("number_of_philosophers time_to_die time_to_eat time_to_sleep");
		printf(" [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	i = 1;
	while (argv[i] != NULL)
	{
		if (phi_atoi((const char *)argv[i], &info_arr[i - 1]) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	init_info(int argc, char **argv, t_info *info)
{
	int	i;

	memset(info, 0, sizeof(t_info));
	info->nb_eat = -1;
	if (check_arg(argc, argv, (int *)info) == 1)
		return (1);
	info->fork_status = (int *)malloc(sizeof(int) * info->nb_philo);
	if (info->fork_status == NULL)
		return (phi_perror(MALLOC_FAIL), 1);
	memset(info->fork_status, 0, sizeof(int) * info->nb_philo);
	info->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
											info->nb_philo);
	if (info->fork == NULL)
		return (phi_perror(MALLOC_FAIL), 1);
	i = 0;
	while (i < info->nb_philo)
	{
		if (pthread_mutex_init(&info->fork[i++], NULL) != 0)
			return (phi_perror(MUTEX_ERROR), 1);
	}
	if (pthread_mutex_init(&info->die, NULL) != 0)
		return (phi_perror(MUTEX_ERROR), 1);
	if (pthread_mutex_init(&info->print, NULL) != 0)
		return (phi_perror(MUTEX_ERROR), 1);
	return (0);
}

int	init_turn(t_info *info)
{
	int	i;

	info->turn = (int *)malloc(sizeof(int) * info->nb_philo);
	if (info->turn == NULL)
		return (phi_perror(MALLOC_FAIL), 1);
	memset(info->turn, 0, sizeof(int) * info->nb_philo);
	i = 0;
	while (i < info->nb_philo - 1)
	{
		info->turn[i] = 1;
		i += 2;
	}
	return (0);
}

int	init_philo(t_philo **philo, t_info *info)
{
	int	i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * info->nb_philo);
	if (*philo == NULL)
		return (phi_perror(MALLOC_FAIL), 1);
	i = 0;
	while (i < info->nb_philo)
	{
		(*philo)[i].nb = i;
		(*philo)[i].eat = 0;
		(*philo)[i].t_last_eat = 0;
		(*philo)[i].state = THINKING;
		(*philo)[i].info = info;
		(*philo)[i].l_fork = &info->fork[i];
		(*philo)[i].r_fork = &info->fork[(i + 1) % info->nb_philo];
		i++;
	}
	return (0);
}
