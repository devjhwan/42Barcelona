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

static int	print_action2(t_philo *philo)
{
	int	ret;

	if (philo->state == TAKING_FORK)
		ret = printf("%d %d has taken a fork\n", \
			get_current_time(philo->offset), philo->nb);
	else if (philo->state == THINKING)
		ret = printf("%d %d is thinking\n", \
			get_current_time(philo->offset), philo->nb);
	else if (philo->state == SLEEPING)
		ret = printf("%d %d is sleeping\n", \
			get_current_time(philo->offset), philo->nb);
	else if (philo->state == EATING)
		ret = printf("%d %d is eating\n", \
			get_current_time(philo->offset), philo->nb);
	else
		ret = printf("%d %d died\n", \
			get_current_time(philo->offset), philo->nb);
	return (ret);
}

void	print_action(t_philo *philo, t_info *info)
{
	int	ret;

	pthread_mutex_lock(&info->print);
	if (info->exit_status == 0)
	{
		ret = print_action2(philo);
		if (philo->state == DEAD)
			info->exit_status = 1;
		if (ret < 0)
		{
			phi_perror(PRINT_ERROR);
			info->exit_status = 1;
		}
	}
	pthread_mutex_unlock(&info->print);
}
