/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 22:12:40 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/29 11:31:30 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	take_forks(t_philosopher *philo, int first, int second)
// {
// 	while (
// 		!(philo->info->forks[first] == philo->index
// 		&& philo->info->forks[second] == philo->index)
// 		&& philo->info->death == 0)
// 	{
// 		pthread_mutex_lock(&philo->info->mutex[first]);
// 		pthread_mutex_lock(&philo->info->mutex[second]);
// 		if (philo->info->forks[first] == -1)
// 		{
// 			print_fork(WAIT_1ST_FORK, philo, philo->index, first);
// 			philo->info->forks[first] = philo->index;
// 			print_fork(FORK, philo, philo->index, first);
// 		}
// 		if (philo->info->forks[second] == -1)
// 		{
// 			print_fork(WAIT_2ND_FORK, philo, philo->index, second);
// 			philo->info->forks[second] = philo->index;
// 			print_fork(FORK, philo, philo->index, second);
// 		}
// 		pthread_mutex_unlock(&philo->info->mutex[first]);
// 		pthread_mutex_unlock(&philo->info->mutex[second]);
// 		check_death(philo);
// 	}
// }

void	take_forks(t_philosopher *philo, int first, int second)
{
	while (!(philo->info->forks[first] == philo->index
			&& philo->info->forks[second] == philo->index)
		&& philo->info->death == 0)
	{
		pthread_mutex_lock(&philo->info->mutex[first]);
		pthread_mutex_lock(&philo->info->mutex[second]);
		if (philo->info->forks[first] == -1)
		{
			philo->info->forks[first] = philo->index;
			print_action(FORK, philo, philo->index);
		}
		if (philo->info->forks[second] == -1)
		{
			philo->info->forks[second] = philo->index;
			print_action(FORK, philo, philo->index);
		}
		pthread_mutex_unlock(&philo->info->mutex[first]);
		pthread_mutex_unlock(&philo->info->mutex[second]);
		check_death(philo);
	}
}

void	philo_eat(t_philosopher *philo, int index)
{
	philo->times_eaten++;
	print_action(EAT, philo, index);
	wait_time(philo, philo->info->time_eat);
}

// void	leave_forks(t_philosopher *philo, int first, int second)
// {
// 	philo->info->forks[first] = -1;
// 	print_fork(LEAVE, philo, philo->index, first);
// 	philo->info->forks[second] = -1;
// 	print_fork(LEAVE, philo, philo->index, second);
// }

void	leave_forks(t_philosopher *philo, int first, int second)
{
	philo->info->forks[first] = -1;
	philo->info->forks[second] = -1;
}

void	philo_sleep(t_philosopher *philo, int index)
{
	print_action(SLEEP, philo, index);
	wait_time(philo, philo->info->time_sleep);
}

void	philo_think(t_philosopher *philo, int index)
{
	print_action(THINK, philo, index);
}
