char	*color;

	color = 0;
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



	ANSI_B_BRED
		ANSI_B_GREEN
		ANSI_B_BGREEN
		ANSI_B_YELLOW
		ANSI_B_BYELLOW
		ANSI_B_BLUE
		ANSI_B_BBLUE
		ANSI_B_MAGENTA
		ANSI_B_BMAGENTA
		ANSI_B_CYAN
		ANSI_B_BCYAN
		ANSI_B_BLACK
		ANSI_B_BBLACK
		ANSI_B_WHITE
		ANSI_B_BWHITE
		


// void	take_forks(t_philosopher *philo, int index, int num_philo)
// {
// 	if (index % 2 == 0)
// 	{
// 		pthread_mutex_lock(&philo->info->mutex[index % num_philo]);
// 		print_philo_action(FORK, philo, index, ANSI_F_WHITE);
// 		pthread_mutex_lock(&philo->info->mutex[(index + 1) % num_philo]);
// 		print_philo_action(FORK, philo, index, ANSI_F_WHITE);
// 	}
// 	else
// 	{
// 		pthread_mutex_lock(&philo->info->mutex[(index + 1) % num_philo]);
// 		print_philo_action(FORK, philo, index, ANSI_F_WHITE);
// 		pthread_mutex_lock(&philo->info->mutex[index % num_philo]);
// 		print_philo_action(FORK, philo, index, ANSI_F_WHITE);
// 	}
// }





/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:18:39 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/27 01:43:05 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_death(t_philosopher *philo)
{
	if (get_elapsed_time_from_meal(philo) > philo->info->time_die)
	{
		print_philo_action(DEATH, philo, philo->index, ANSI_B_RED);
		philo->info->death = 1;
	}
}

void	wait_time(t_philosopher *philo, int time_towait)
{
	while(get_elapsed_time(philo) <= time_towait)
	{
		check_death(philo);
		if (philo->info->death == 1)
			break ;
		usleep(1);
	}
}


void	take_forks(t_philosopher *philo, int left, int right)
{
	while (1)
	{
		pthread_mutex_lock(&philo->info->mutex[left]);
		if (philo->info->forks[left] == 0)
		{
			philo->info->forks[left] = 1;
			print_philo_action(FORK, philo, philo->index, ANSI_F_WHITE);
		}
		pthread_mutex_unlock(&philo->info->mutex[left]);


		pthread_mutex_lock(&philo->info->mutex[right]);
		if (philo->info->forks[right] == 0)
		{
			philo->info->forks[right] = 1;
			print_philo_action(FORK, philo, philo->index, ANSI_F_WHITE);
		}
		pthread_mutex_unlock(&philo->info->mutex[right]);
		
		// if (philo->info->forks[left] == 1 && philo->info->forks[right] == 1)
		// {
		// 	return ;
		// }
		check_death(philo);
	}
}


void	philo_eat(t_philosopher *philo, int index)
{
	check_death(philo);
	if (philo->info->death == 1)
		return ;
	philo->times_eaten++;
	print_philo_action(EAT, philo, index, ANSI_F_GREEN);
	wait_time(philo, philo->info->time_eat);
}

void	leave_forks(t_philosopher *philo, int left, int right)
{
	pthread_mutex_lock(&philo->info->mutex[left]);
	philo->info->forks[left] = 0;
	pthread_mutex_unlock(&philo->info->mutex[left]);
	pthread_mutex_lock(&philo->info->mutex[right]);
	philo->info->forks[right] = 0;
	pthread_mutex_unlock(&philo->info->mutex[right]);
	check_death(philo);
}

void	philo_sleep(t_philosopher *philo, int index)
{
	print_philo_action(SLEEP, philo, index, ANSI_F_WHITE);
	wait_time(philo, philo->info->time_sleep);
}

void	philo_think(t_philosopher *philo, int index)
{
	print_philo_action(THINK, philo, index, ANSI_F_WHITE);
	check_death(philo);
}

void	*routine(void *arg)
{
	t_philosopher	*philo;
	int				left;
	int				right;

	philo = (t_philosopher *)arg;
	left = (philo->index + 0) % philo->info->num_philos;
	right = (philo->index + 1) % philo->info->num_philos;
	while (philo->info->death == 0)
	{
		philo_think(philo, philo->index);
		if (philo->index % 2 == 0)
			take_forks(philo, left, right);
		else
			take_forks(philo, right, left);
		philo_eat(philo, philo->index);
		leave_forks(philo, left, right);
		if (philo->times_eaten >= philo->info->times_to_eat
			&& philo->info->times_to_eat > 0)
			break ;
		philo_sleep(philo, philo->index);
	}
	free(philo);
	return (0);
}
