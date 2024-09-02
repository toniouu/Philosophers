/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:42:47 by atovoman          #+#    #+#             */
/*   Updated: 2024/09/02 10:52:52 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	print_error(char *error)
{
	printf(RED BOLD"ERROR : %s\n", error);
}

void	print_action(t_prog *prog, t_philo philo, char *action)
{
	if (prog->end_flags != 0)
		return ;
	printf("%ld %d %s\n", my_get_time() - prog->start, philo.id, action);
}

int	my_usleep(t_prog *prog, t_philo philo, long t)
{
	long	act;

	act = my_get_time();
	while (my_get_time() <= act + t)
	{
		if (my_get_time() - philo.last_eat >= prog->ttd)
			return (-1);
		if (prog->end_flags != 0)
			return (-1);
		usleep(500);
	}
	return (0);
}

int	my_eating_usleep(t_prog *prog, long t)
{
	long	act;

	act = my_get_time();
	while (my_get_time() <= act + t)
	{
		if (prog->end_flags != 0)
			return (-1);
		usleep(500);
	}
	return (0);
}
