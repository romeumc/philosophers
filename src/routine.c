/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:18:39 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/24 16:19:15 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philosopher *philo;

	philo = (t_philosopher *)arg;
	
	sleep(1);
	int j;
	if (philo->index == 99)
		j = 0;
	else
		j = philo->index + 1;


	pthread_mutex_lock(&philo->info->mutex[philo->index]);
	pthread_mutex_lock(&philo->info->mutex[j]);
	
	//philo->info->times_to_eat++;
	// if (philo->number == 4)
	// 	philo->times_eaten++;
	
	printf(ANSI_F_BGREEN "idx:%d "ANSI_RESET, philo->index);
	
	printf(ANSI_F_BGREEN "num:%d "ANSI_RESET, philo->info->num_philos);
	// printf(ANSI_F_YELLOW "times_eaten:%d " ANSI_RESET, philo->times_eaten++);
	printf("\n");

	printf("test from thread\n");
	pthread_mutex_unlock(&philo->info->mutex[philo->index]);
	pthread_mutex_unlock(&philo->info->mutex[j]);

	
	usleep(300000);
	printf(".");

	free(philo);
	return (0);
}