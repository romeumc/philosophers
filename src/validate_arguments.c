/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:56:53 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/25 13:58:21 by rmartins         ###   ########.fr       */
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
		i++;
	}
	return (EXIT_SUCCESS);
}

void	load_args_info(int argc, char **argv, t_philo_args *philo_info)
{
	philo_info->num_philos = ft_atoi(argv[1]);
	philo_info->time_die = ft_atoi(argv[2]) * 1000;
	philo_info->time_eat = ft_atoi(argv[3]) * 1000;
	philo_info->time_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		philo_info->times_to_eat = ft_atoi(argv[5]);
	else
		philo_info->times_to_eat = -1;
}
