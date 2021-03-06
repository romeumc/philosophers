/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:44:43 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/29 10:55:29 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

char	*get_philo_color_byindex(int philo_index)
{
	char	*color;

	color = 0;
	if (philo_index % 10 == 0)
		color = strdup(ANSI_F_BRED);
	else if (philo_index % 10 == 1)
		color = strdup(ANSI_F_BGREEN);
	else if (philo_index % 10 == 2)
		color = strdup(ANSI_F_YELLOW);
	else if (philo_index % 10 == 3)
		color = strdup(ANSI_F_BBLUE);
	else if (philo_index % 10 == 4)
		color = strdup(ANSI_F_BMAGENTA);
	else if (philo_index % 10 == 5)
		color = strdup(ANSI_F_CYAN);
	else if (philo_index % 10 == 6)
		color = strdup(ANSI_F_BCYAN);
	else if (philo_index % 10 == 7)
		color = strdup(ANSI_F_WHITE);
	else if (philo_index % 10 == 8)
		color = strdup(ANSI_F_BYELLOW);
	else if (philo_index % 10 == 9)
		color = strdup(ANSI_F_BBLACK);
	return (color);
}

void	print_action(char *action, t_philosopher *philo, int index)
{
	int		time;
	char	*philo_color;

	pthread_mutex_lock(&philo->info->mutex[philo->info->num_philos + 1]);
	philo_color = get_philo_color_byindex(index);
	time = get_time_stamp_action(philo) / 1000;
	if (ft_strcmp(action, EAT) == 0)
		philo->last_meal = philo->last_action;
	if (philo->info->death != 1)
	{
		if (ft_strcmp(action, DEATH) == 0)
			philo->info->death = 1;
		printf("%dms\t %s%d" ANSI_RESET " %s\n",
			time, philo_color, index + 1, action);
	}
	free(philo_color);
	pthread_mutex_unlock(&philo->info->mutex[philo->info->num_philos + 1]);
}

void	print_fork(char *action, t_philosopher *philo, int index, int fork)
{
	int		time;
	char	*philo_color;

	pthread_mutex_lock(&philo->info->mutex[philo->info->num_philos + 1]);
	philo_color = get_philo_color_byindex(index);
	time = get_time_stamp_action(philo) / 1000;
	if (philo->info->death != 1)
	{
		printf("%dms\t %s%d" ANSI_RESET " %s [%d]\n",
			time, philo_color, index + 1, action, fork + 1);
	}
	free(philo_color);
	pthread_mutex_unlock(&philo->info->mutex[philo->info->num_philos + 1]);
}
