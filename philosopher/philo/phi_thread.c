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
		printf("[%d ms] philo nb %d died\n", \
			get_current_time(philo->offset), philo->nb);
		info->exit_status = 1;
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
	if (info->fork_status[philo->nb] == 0 ||
		info->fork_status[(philo->nb + 1) % info->nb_philo] == 0)
	{
		info->fork_status[philo->nb] = 1;
		info->fork_status[(philo->nb + 1) % info->nb_philo] = 1;
		philo->state = EATING;
		philo->t_last_eat = get_current_time(philo->offset);
		printf("[%d ms] philo nb %d starts to %dth eat\n", \
			get_current_time(philo->offset), philo->nb, philo->eat + 1);
	}
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	if (philo->state == THINKING)
		usleep(10);
}

static void	philo_eat(t_philo *philo, t_info *info)
{
	if (get_current_time(philo->offset) - philo->t_last_eat >= info->t_eat)
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
		printf("[%d ms] philo nb %d starts to sleep\n", \
			get_current_time(philo->offset), philo->nb);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
	if (philo->state == EATING)
		usleep(10);
}

static void	philo_sleep(t_philo *philo, t_info *info)
{
	if (get_current_time(philo->offset) - philo->t_last_sleep >= info->t_sleep)
	{
		printf("[%d ms] philo nb %d starts to think\n", \
			get_current_time(philo->offset), philo->nb);
		philo->state = THINKING;
	}
	if (philo->state == SLEEPING)
		usleep(10);
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
