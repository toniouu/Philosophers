/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:10:45 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/13 16:49:02 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_not_digit(char **av)
{
	int	x;
	int	y;

	y = 1;
	while (av[y] != NULL)
	{
		x = 0;
		while (av[y][x] == 32)
		{
			if (av[y][x + 1] == '\0')
				return (-1);
			x++;
		}
		while (av[y][x] != '\0')
		{
			if (av[y][x] == '+' && !ft_is_digit(av[y][x + 1]))
				return (-1);
			if (!ft_is_digit(av[y][x]) && av[y][x] != '+')
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}
