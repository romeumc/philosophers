/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 22:30:42 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/22 15:29:52 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	validate_args(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		print_error("Wrong usage: ", "./philo #phi #die #eat #sleep [#times]");
		return (EXIT_FAILURE);
	}
	i = 1;
	while (i < argc)
	{
		if (ft_isnumber(argv[i]) == FALSE || ft_atoi(argv[i]) <= 0)
		{
			print_error("ERROR: ", "Argument is not valid");
			return (EXIT_FAILURE);
		}
		//printf("i:%d [%s]\n", i, argv[i]);
		i++;
	}
	if (ft_atoi(argv[1]) < 2)
	{
		print_error("ERROR: ", "Insufficient number of philosophers");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	load_data(int argc, char **argv, t_philo *philo)
{
	philo->number_philos = ft_atoi(argv[1]);
	philo->time_die = ft_atoi(argv[2]);
	philo->time_eat = ft_atoi(argv[3]);
	philo->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->times_to_eat = ft_atoi(argv[5]);
	else
		philo->times_to_eat = -1;
}

void *routine()
{
	printf("test from thread\n");
	sleep(2);
	printf("teste\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	philo;
	pthread_t	t1;
	pthread_t	t2;

	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return (0);
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return (0);
	if (pthread_join(t1, NULL) != 0)
		return (1);
	if (pthread_join(t2, NULL) != 0)
		return (1);
	
	if (validate_args(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	load_data(argc, argv, &philo);
	printf(ANSI_B_BCYAN " ok " ANSI_RESET);
	return (0);
}
