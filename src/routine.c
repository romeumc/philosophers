/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:18:39 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/25 17:58:54 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		get_time_stamp(t_philosopher *philo)
{
	long	seconds;
	int		useconds;
	int		time;

	gettimeofday(&philo->last_action, NULL);
	//time = 0;
	useconds = philo->last_action.tv_usec - philo->info->start_time.tv_usec;
	seconds = philo->last_action.tv_sec - philo->info->start_time.tv_sec;
	time = seconds * 1000 + useconds / 1000;
	return (time);
}

void	print_philo_action(char *action, t_philosopher *philo, int index, char *color)
{
	int	time;

	if (philo->index % 10 == 0)
		color = strdup(ANSI_F_RED);
	else if (philo->index % 10 == 1)
		color = strdup(ANSI_F_BRED);
	else if (philo->index % 10 == 2)
		color = strdup(ANSI_F_GREEN);
	else if (philo->index % 10 == 3)
		color = strdup(ANSI_F_BGREEN);
	else if (philo->index % 10 == 4)
		color = strdup(ANSI_F_YELLOW);
	else if (philo->index % 10 == 5)
		color = strdup(ANSI_F_BYELLOW);
	else if (philo->index % 10 == 6)
		color = strdup(ANSI_F_BLUE);
	else if (philo->index % 10 == 7)
		color = strdup(ANSI_F_BBLUE);
	else if (philo->index % 10 == 8)
		color = strdup(ANSI_F_MAGENTA);
	else if (philo->index % 10 == 9)
		color = strdup(ANSI_F_BMAGENTA);

	time = get_time_stamp(philo);
	printf("%s%dms %d %s" ANSI_RESET "\n", color, time, index + 1, action);
}

void	take_forks(t_philosopher *philo, int index, int num_philo)
{
	if (index % 2 == 0)
	{
		pthread_mutex_lock(&philo->info->mutex[index % num_philo]);
		//printf ("fork[%d] - ", (index % num_philo) + 1);
		print_philo_action(FORK, philo, index, ANSI_F_WHITE);

		pthread_mutex_lock(&philo->info->mutex[(index + 1) % num_philo]);
		//printf ("fork[%d] - ", ((index +1 ) % num_philo) + 1);
		print_philo_action(FORK, philo, index, ANSI_F_WHITE);
	}
	else
	{
		pthread_mutex_lock(&philo->info->mutex[(index + 1) % num_philo]);
		//printf ("fork[%d] - ", ((index +1 ) % num_philo) + 1);
		print_philo_action(FORK, philo, index, ANSI_F_WHITE);

		pthread_mutex_lock(&philo->info->mutex[index % num_philo]);
		//printf ("fork[%d] - ", (index % num_philo) + 1);
		print_philo_action(FORK, philo, index, ANSI_F_WHITE);
	}
}

void	philo_eat(t_philosopher *philo, int index)
{
	print_philo_action(EAT, philo, index, ANSI_F_GREEN);
	philo->times_eaten++;
	//printf(ANSI_B_BCYAN " philosopher %d - eats:%d" ANSI_RESET "\n", philo->index, philo->times_eaten);
}

void	leave_forks(t_philosopher *philo, int index, int num_philo)
{
	pthread_mutex_unlock(&philo->info->mutex[index % num_philo]);
	pthread_mutex_unlock(&philo->info->mutex[(index + 1) % num_philo]);
}


void	philo_sleep(t_philosopher *philo, int index)
{
	print_philo_action(SLEEP, philo, index, ANSI_F_YELLOW);
}

void	*routine(void *arg)
{
	t_philosopher	*philo;
	
	philo = (t_philosopher *)arg;
	while (1)
	{	
		take_forks(philo, philo->index, philo->info->num_philos);
		philo_eat(philo, philo->index);
		leave_forks(philo, philo->index, philo->info->num_philos);
		philo_sleep(philo, philo->index);
		
		if (philo->times_eaten >= philo->info->times_to_eat && 
			philo->info->times_to_eat > 0)
			break ;
		
		//sleep(1);
	}
	
	usleep(300000);
	printf(".");

	free(philo);
	return (0);
}