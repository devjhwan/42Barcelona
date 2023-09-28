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

#include "philosopher.h"
#include <string.h>

void	create_threads(t_philo *philo, t_info *info)
{
	int		i;

	i = 0;
	while (i < info->nb_philo)
	{
		if (pthread_create(&(philo[i].thid), NULL, \
							thread_main, (void *)(&philo[i])) != 0)
		{
			printf("Thread creating failed at thread number %d.\n", i);
			info->exit_status = 1;
			break ;
		}
		i++;
	}
	if (i < info->nb_philo)
		philo[i].nb = -1;
}

void	wait_threads(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philo && philo[i].nb >= 0)
		pthread_join(philo[i++].thid, NULL);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;

	philo = NULL;
	if (init_info(argc, argv, &info) == 1)
		return (free_info(&info), 0);
	if (init_philo(&philo, &info) == 1)
		return (free_info(&info), free_philo(philo), 0);
	create_threads(philo, &info);
	wait_threads(philo, &info);
	free_info(&info);
	free_philo(philo);
	return (0);
}
