/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 22:30:42 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/27 00:35:19 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo_args	philo_args;

	// while (1)
	// {
	// 	gettimeofday(&curr_time, NULL);
	// 	//printf("time:%d\n", (curr_time.tv_usec - philo_args.start_time.tv_usec));
	// 	printf("seconds : %ld\nmicro seconds : %d", curr_time.tv_sec, curr_time.tv_usec);
	// }

	if (validate_args(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	load_args_info(argc, argv, &philo_args);
	if (init_extra_info(&philo_args) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (create_mutexes(&philo_args) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (malloc_threads(&philo_args) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	gettimeofday(&philo_args.start_time, NULL);
	if (create_philosophers(&philo_args))
		return (EXIT_FAILURE);
	if (destroy_philosophers(&philo_args) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (destroy_mutexes(&philo_args) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	free(philo_args.forks);
	return (EXIT_SUCCESS);
}