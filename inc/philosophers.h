/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 22:31:41 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/22 00:36:30 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define FALSE 1
# define TRUE 0

# include <stdio.h>
# include "ft_ansi.h"
# include "utils.h"

typedef struct s_philo
{
	int	number_philos;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	times_to_eat;
}	t_philo;

void	print_error(char *header, char *error);
void	print_message(char *header, char *message);

#endif