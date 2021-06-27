/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 22:12:40 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/27 22:59:22 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
		if (philo->info->forks[left] == philo->index
			&& philo->info->forks[right] == philo->index)
		{
			print_action(FORK, philo, philo->index, ANSI_F_WHITE);
			print_action(FORK, philo, philo->index, ANSI_F_WHITE);
			break ;
		}
	}
}

void	philo_eat(t_philosopher *philo, int index)
{
	philo->times_eaten++;
	print_action(EAT, philo, index, ANSI_F_GREEN);
	wait_time(philo, philo->info->time_eat);
}

void	leave_forks(t_philosopher *philo, int left, int right)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(&philo->info->mutex[left]);
		philo->info->forks[left] = -1;
		pthread_mutex_unlock(&philo->info->mutex[left]);
		pthread_mutex_lock(&philo->info->mutex[right]);
		philo->info->forks[right] = -1;
		pthread_mutex_unlock(&philo->info->mutex[right]);
	}
	else
	{
		pthread_mutex_lock(&philo->info->mutex[right]);
		philo->info->forks[right] = -1;
		pthread_mutex_unlock(&philo->info->mutex[right]);
		pthread_mutex_lock(&philo->info->mutex[left]);
		philo->info->forks[left] = -1;
		pthread_mutex_unlock(&philo->info->mutex[left]);
	}
}

void	philo_sleep(t_philosopher *philo, int index)
{
	print_action(SLEEP, philo, index, ANSI_F_WHITE);
	wait_time(philo, philo->info->time_sleep);
}

void	philo_think(t_philosopher *philo, int index)
{
	print_action(THINK, philo, index, ANSI_F_WHITE);
}
