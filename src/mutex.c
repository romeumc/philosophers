/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:15:58 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/24 11:21:17 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_mutexes(t_philosopher *philo)
{
	int	i;

	philo->mutex = malloc(sizeof(pthread_mutex_t) * philo->info.num_philos);
	if (philo->mutex == NULL)
	{
		print_error("ERROR: ", "Cannot allocate mutex");
		return (EXIT_FAILURE);
	}
	i = 0;
	while (i < philo->info.num_philos)
	{
		if (pthread_mutex_init(&philo->mutex[i], NULL) != 0)
		{
			print_error("ERROR: ", "Cannot create mutex");
			free(philo->mutex);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

