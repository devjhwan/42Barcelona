/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:51:20 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/27 20:51:22 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdlib.h>

typedef struct timeval t_time;

int	get_current_time(t_time	offset)
{
	t_time			current;
	int				time;

	gettimeofday(&current, NULL);
	time = (current.tv_sec - offset.tv_sec) * 1000 + \
			(current.tv_usec - offset.tv_usec) / 1000;
	return (time);
}