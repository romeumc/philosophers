/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 22:31:41 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/24 18:06:12 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define FALSE 1
# define TRUE 0

# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include "ft_ansi.h"
# include "utils.h"

typedef struct s_philo_args
{
	int	num_philos;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	times_to_eat;
	pthread_mutex_t	*mutex;
	pthread_t		*thread;
}	t_philo_args;

typedef struct s_philosopher
{
	t_philo_args	*info;
	int				number;
	int				times_eaten;
	int				*next_to_eat;
	int				index;
}	t_philosopher;

void	print_error(char *header, char *error);
void	print_message(char *header, char *message);
int		validate_args(int argc, char **argv);
void	load_args_info(int argc, char **argv, t_philo_args *philo_info);

int		create_mutexes(t_philo_args *info);
int		malloc_threads(t_philo_args *philo_args);
int		create_philosophers(t_philo_args *philo_args);
int		destroy_philosophers(t_philo_args *philo_args);
int		destroy_mutexes(t_philo_args *philo_args);
void	*routine(void *arg);

#endif