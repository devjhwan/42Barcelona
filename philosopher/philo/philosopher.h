/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:48:25 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/24 20:48:27 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define INT_MAX 2147483647
typedef struct timeval t_time;

typedef struct s_info
{
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_eat;
	int				total_eat;
	int				exit_status;
	int				turn;
	int				*queue;
	int				*fork_status;
	pthread_mutex_t	*fork;
	pthread_mutex_t	die;
	pthread_mutex_t	print;
}	t_info;

# define THINKING 0
# define EATING 1
# define SLEEPING 2
# define DEAD 3

typedef struct s_philo
{
	int				nb;
	int				eat;
	int				t_last_eat;
	int				t_last_sleep;
	int				state;
	t_info			*info;
	t_time			offset;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_t		thid;
}	t_philo;

int		phi_atoi(const char *str, int *num);
int		check_arg(int argc, char **argv, int *info_arr);
int		init_info(int argc, char **argv, t_info *info);
int		init_queue(t_info *info);
int		init_philo(t_philo **philo, t_info *info);
void	free_info(t_info *info);
void	free_philo(t_philo *philo);
void	*thread_main(void *var);
int		get_current_time(t_time	offset);

# define NEGATIVE 1
# define BAD_INPUT 2
# define OUT_OF_MAX 3
# define MALLOC_FAIL 4
# define THREAD_FAIL 5
# define MUTEX_ERROR 6
# define PRINT_ERROR 7

void	phi_perror(int errno);
void	print_action(t_philo *philo, t_info *info);

#endif
