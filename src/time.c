/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:41:53 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/27 16:29:38 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static long long	get_time_diff(struct timeval start, struct timeval current)
{
	long long	seconds;
	int			useconds;

	useconds = current.tv_usec - start.tv_usec;
	seconds = current.tv_sec - start.tv_sec;
	return (seconds * 1000 * 1000 + useconds);
}

long long	get_time_stamp_action(t_philosopher *philo)
{
	gettimeofday(&philo->last_action, NULL);
	return (get_time_diff(philo->info->start_time, philo->last_action));
}

long long	get_elapsed_time(t_philosopher *philo)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (get_time_diff(philo->last_action, current_time));
}

long long	get_elapsed_time_from_meal(t_philosopher *philo)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (get_time_diff(philo->last_meal, current_time));
}
