/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_destroy_philosophers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:46:08 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/24 01:15:17 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_mutexes(t_philo_args *philo_arg)
{
	int	i;

	philo_arg->mutex = malloc(sizeof(pthread_mutex_t) * philo_arg->num_philos);
	if (philo_arg->mutex == NULL)
	{
		print_error("ERROR: ", "Cannot allocate mutex");
		return (EXIT_FAILURE);
	}
	i = 0;
	while (i < philo_arg->num_philos)
	{
		if (pthread_mutex_init(&philo_arg->mutex[i], NULL) != 0)
		{
			print_error("ERROR: ", "Cannot create mutex");
			free(philo_arg->mutex);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	malloc_threads(t_philo_args *philo_args)
{
	philo_args->thread = malloc(sizeof(pthread_t) * philo_args->num_philos);
	if (philo_args->thread == NULL)
	{
		print_error("ERROR: ", "Cannot allocate thread");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	destroy_mutexes(t_philo_args *philo_args)
{
	int	i;

	i = 0;
	while (i < philo_args->num_philos)
	{
		if (pthread_mutex_destroy(&philo_args->mutex[i]) != 0)
		{
			print_error("ERROR: ", "Falied to destroy mutex");
			free(philo_args->mutex);
			return (EXIT_FAILURE);
		}
		i++;
	}
	free(philo_args->mutex);
	return (EXIT_SUCCESS);
}

int	create_philosophers(t_philosopher *philo, t_philo_args *philo_args)
{
	int	i;

	i = 0;
	while (i < philo_args->num_philos)
	{
		philo->info = philo_args;
		philo->number = i;
		philo->times_eaten = 0;
		if (philo_args->thread == NULL)
		{
			print_error("ERROR: ", "Cannot allocate threads");
			return (EXIT_FAILURE);
		}
		if (pthread_create(&philo->info->thread[i], NULL, &routine, philo) != 0)
		{
			print_error("ERROR: ", "Cannot create thread");
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	destroy_philosophers(t_philo_args *philo_args)
{
	int	i;

	i = 0;
	while (i < philo_args->num_philos)
	{
		if (pthread_join(philo_args->thread[i], NULL) != 0)
		{
			print_error("ERROR: ", "Falied to join thread");
			return (EXIT_FAILURE);
		}
		i++;
	}
	free(philo_args->thread);
	return (EXIT_SUCCESS);
}
