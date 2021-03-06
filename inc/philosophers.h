/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 22:31:41 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/29 10:53:26 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define FALSE 1
# define TRUE 0

# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include "ft_ansi.h"
# include "utils.h"

typedef struct s_philo_args
{
	int				num_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				times_to_eat;
	int				*forks;
	pthread_mutex_t	*mutex;
	pthread_t		*thread;
	struct timeval	start_time;
	int				death;
}	t_philo_args;

typedef struct s_philosopher
{
	t_philo_args	*info;
	int				index;
	struct timeval	last_action;
	struct timeval	last_meal;
	int				times_eaten;
}	t_philosopher;

# define FORK	"has taken a fork"
# define EAT	"\033[32mis eating\033[0m"
# define SLEEP	"is sleeping"
# define THINK	"is thinking"
# define DEATH	"\033[41mdied\033[0m"
# define LEAVE	"\033[44mleave forks\033[0m"
# define WAIT_2ND_FORK "\033[45m WAIT 2nd \033[0m"
# define WAIT_1ST_FORK "\033[42;1m WAIT 1st \033[0m"

void		print_error(char *header, char *error);
void		print_message(char *header, char *message);
int			validate_args(int argc, char **argv);
void		load_args_info(int argc, char **argv, t_philo_args *philo_info);
int			init_extra_info(t_philo_args *philo_info);

int			create_mutexes(t_philo_args *info);
int			malloc_threads(t_philo_args *philo_args);
int			create_philosophers(t_philo_args *philo_args);
int			create_single_philosopher(t_philo_args *philo_args);
int			destroy_philosophers(t_philo_args *philo_args);
int			destroy_mutexes(t_philo_args *philo_args);
void		*routine(void *arg);
void		print_action(char *action, t_philosopher *philo, int index);
void		print_fork(char *action, t_philosopher *philo, int index, int fork);
void		wait_time(t_philosopher *philo, int time_towait);
void		check_death(t_philosopher *philo);

void		take_forks(t_philosopher *philo, int left, int right);
void		philo_eat(t_philosopher *philo, int index);
void		leave_forks(t_philosopher *philo, int left, int right);
void		philo_sleep(t_philosopher *philo, int index);
void		philo_think(t_philosopher *philo, int index);

long long	get_time_stamp_action(t_philosopher *philo);
long long	get_elapsed_time(t_philosopher *philo);
long long	get_elapsed_time_from_meal(t_philosopher *philo);

#endif