/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 21:29:33 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/28 21:29:35 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	free_info(t_info *info)
{
	int	i;

	i = 0;
	if (info->fork != NULL)
	{
		while (i < info->nb_philo)
			pthread_mutex_destroy(&info->fork[i++]);
	}
	pthread_mutex_destroy(&info->die);
	pthread_mutex_destroy(&info->print);
	free(info->fork_status);
	free(info->fork);
	free(info->turn);
}

void	free_philo(t_philo *philo)
{
	free(philo);
}
