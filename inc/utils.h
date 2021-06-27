/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 23:33:15 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/27 20:33:50 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int			ft_isnumber(char *str);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);
int			ft_atoi(const char *nptr);
long long	ft_atoll(const char *nptr);
void		ft_putstr(char *s);
int			ft_putchar(int c);
int			ft_strcmp(const char *s1, const char *s2);

#endif