/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:18:39 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/24 01:22:14 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philosopher *philo;

	philo = (t_philosopher *)arg;
	
	pthread_mutex_lock(&philo->info->mutex[0]);
	philo->info->times_to_eat++;
	// if (philo->number == 4)
	// 	philo->times_eaten++;
	pthread_mutex_unlock(&philo->info->mutex[0]);
	sleep(1);
	
	printf(ANSI_F_BGREEN "num:%d idx:%d times:%d "ANSI_RESET, philo->info->num_philos, philo->number, philo->info->times_to_eat);
	printf(ANSI_F_YELLOW "times_eaten:%d " ANSI_RESET, philo->times_eaten++);
	printf("\n");

	printf("test from thread\n");
	usleep(300000);
	printf(".");
	return (0);
}