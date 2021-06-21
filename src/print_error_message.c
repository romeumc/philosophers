/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_message.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:26:45 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/22 00:08:55 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_error(char *header, char *error)
{
	ft_putstr(ANSI_F_BRED);
	ft_putstr(header);
	ft_putstr(ANSI_RESET);
	ft_putstr(error);
	ft_putstr("\n");
}

void	print_message(char *header, char *message)
{
	ft_putstr(header);
	ft_putstr(ANSI_F_BGREEN);
	ft_putstr(message);
	ft_putstr(ANSI_RESET);
	ft_putstr("\n");
}
