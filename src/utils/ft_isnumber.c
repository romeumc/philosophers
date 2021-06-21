/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 23:32:44 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/22 00:19:24 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_isnumber(char *str)
{
	size_t	i;
	int		flag;

	i = 0;
	flag = EXIT_SUCCESS;
	if (str[i] == '-' || str[i] == '+')
	{
		flag = EXIT_FAILURE;
		i++;
	}
	while (i < ft_strlen(str))
	{
		if (!(ft_isdigit(str[i])))
			return (EXIT_FAILURE);
		i++;
		flag = EXIT_SUCCESS;
	}
	if (ft_atoll(str) > INT_MAX || ft_atoll(str) < INT_MIN)
		flag = EXIT_FAILURE;
	return (flag);
}
