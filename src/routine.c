/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:18:39 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/27 21:30:54 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_death(t_philosopher *philo)
{
	if (get_elapsed_time_from_meal(philo) > philo->info->time_die + 10000)
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
		pthread_mutex_lock(&philo->info->mutex[right]);
		if (philo->info->forks[left] == -1 && philo->info->forks[right] == -1)
		{
			philo->info->forks[left] = philo->index;
			philo->info->forks[right] = philo->index;
		}
		pthread_mutex_unlock(&philo->info->mutex[left]);
		pthread_mutex_unlock(&philo->info->mutex[right]);

		check_death(philo);
		if (philo->info->death == 1)
			break ;

		if (philo->info->forks[left] == philo->index && philo->info->forks[right] == philo->index)
		{
			print_philo_action(FORK, philo, philo->index, ANSI_F_WHITE);
			print_philo_action(FORK, philo, philo->index, ANSI_F_WHITE);
			break ;
		}
	}
}

void	philo_eat(t_philosopher *philo, int index)
{
	// if (philo->info->death == 1)
	// 	return ;
	philo->times_eaten++;
	print_philo_action(EAT, philo, index, ANSI_F_GREEN);
	wait_time(philo, philo->info->time_eat);
}

void	leave_forks(t_philosopher *philo, int left, int right)
{
	pthread_mutex_lock(&philo->info->mutex[left]);
	philo->info->forks[left] = -1;
	pthread_mutex_unlock(&philo->info->mutex[left]);
	pthread_mutex_lock(&philo->info->mutex[right]);
	philo->info->forks[right] = -1;
	pthread_mutex_unlock(&philo->info->mutex[right]);
}

void	philo_sleep(t_philosopher *philo, int index)
{
	print_philo_action(SLEEP, philo, index, ANSI_F_WHITE);
	wait_time(philo, philo->info->time_sleep);
}

void	philo_think(t_philosopher *philo, int index)
{
	print_philo_action(THINK, philo, index, ANSI_F_WHITE);
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
