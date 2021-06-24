/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 22:30:42 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/24 18:06:15 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// int	main(int argc, char **argv)
// {
// 	t_philo_args	philo_args;
// 	t_philosopher	*philo;

// 	if (validate_args(argc, argv) == EXIT_FAILURE)
// 		return (EXIT_FAILURE);
// 	load_args_info(argc, argv, &philo_args);
// 	if (create_mutexes(&philo_args) == EXIT_FAILURE)
// 		return (EXIT_FAILURE);
// 	if (malloc_threads(&philo_args) == EXIT_FAILURE)
// 		return (EXIT_FAILURE);
// 	philo = malloc(sizeof(t_philosopher) * philo_args.num_philos);
// 	if (philo == NULL)
// 	{
// 		print_error("ERROR", "Cannot allocate philosophers");
// 		return (EXIT_FAILURE);
// 	}
// 	if (create_philosophers(&philo, &philo_args) == EXIT_FAILURE)
// 		return (EXIT_FAILURE);
// 	if (destroy_mutexes(&philo_args) == EXIT_FAILURE)
// 		return (EXIT_FAILURE);
// 	destroy_philosophers(&philo_args);
// 	free(philo);
// 	return (EXIT_SUCCESS);
// }


int	main(int argc, char **argv)
{
	t_philo_args	philo_args;
	
	if (validate_args(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	load_args_info(argc, argv, &philo_args);
	if (create_mutexes(&philo_args) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (malloc_threads(&philo_args) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (create_philosophers(&philo_args))
		return (EXIT_FAILURE);
	
	destroy_philosophers(&philo_args);
	if (destroy_mutexes(&philo_args) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
