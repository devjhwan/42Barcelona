/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:17:34 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/27 18:17:36 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	philo_dies(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&info->die);
	if (get_current_time(philo->offset) - philo->t_last_eat >= info->t_die && \
		info->exit_status == 0)
	{
		philo->state = DEAD;
		print_action(philo, info);
		pthread_mutex_unlock(&info->die);
		return (1);
	}
	pthread_mutex_unlock(&info->die);
	return (0);
}

/*tries to get forks*/
static void	philo_think(t_philo *philo, t_info *info)
{
	if (info->nb_philo == 1)
		return ;
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
	if (info->exit_status == 0 && \
		info->queue[info->turn] == philo->nb && \
		info->fork_status[philo->nb] == 0 &&
		info->fork_status[(philo->nb + 1) % info->nb_philo] == 0)
	{
		info->turn = (info->turn + 1) % info->nb_philo;
		info->fork_status[philo->nb] = 1;
		info->fork_status[(philo->nb + 1) % info->nb_philo] = 1;
		philo->state = EATING;
		philo->t_last_eat = get_current_time(philo->offset);
		print_action(philo, info);
	}
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	if (philo->state == THINKING)
		usleep(100);
}

static void	philo_eat(t_philo *philo, t_info *info)
{
	if (info->exit_status == 0 && \
		get_current_time(philo->offset) - philo->t_last_eat >= info->t_eat)
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
		info->fork_status[philo->nb] = 0;
		info->fork_status[(philo->nb + 1) % info->nb_philo] = 0;
		philo->eat += 1;
		if (philo->eat == info->nb_eat)
			info->total_eat += 1;
		philo->state = SLEEPING;
		philo->t_last_sleep = get_current_time(philo->offset);
		print_action(philo, info);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
	if (philo->state == EATING)
		usleep(100);
}

static void	philo_sleep(t_philo *philo, t_info *info)
{
	if (info->exit_status == 0 && \
		get_current_time(philo->offset) - philo->t_last_sleep >= info->t_sleep)
	{
		philo->state = THINKING;
		print_action(philo, info);
	}
	if (philo->state == SLEEPING)
		usleep(100);
}

void	*thread_main(void *var)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)var;
	info = (t_info *)philo->info;
	gettimeofday(&philo->offset, NULL);
	while (info->exit_status == 0 && \
			info->total_eat != info->nb_philo)
	{
		if (philo_dies(philo, info) == 1)
			break;
		if (philo->state == THINKING)
			philo_think(philo, info);
		else if (philo->state == EATING)
			philo_eat(philo, info);
		else
			philo_sleep(philo, info);
	}
	return (NULL);
}
