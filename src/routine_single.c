/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_single.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 22:54:48 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/28 16:10:38 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*single_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	print_action(THINK, philo, philo->index);
	print_action(FORK, philo, philo->index);
	usleep(philo->info->time_die);
	print_action(DEATH, philo, philo->index);
	return (0);
}

int	create_single_philosopher(t_philo_args *philo_args)
{
	t_philosopher	*philo;

	philo = malloc(sizeof(t_philosopher));
	if (philo == NULL)
	{
		print_error("ERROR", "Cannot allocate philosophers");
		return (EXIT_FAILURE);
	}
	philo->index = 0;
	philo->info = philo_args;
	if (pthread_create(&philo_args->thread[0],
			NULL, &single_routine, philo) != 0)
	{
		print_error ("ERROR: ", "Cannot create thread");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
