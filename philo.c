/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:13:18 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/13 16:49:00 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	valid_arguments(char **av, t_philo *philo)
{
	philo->nbr = ft_atoi(av[1]);
	if (philo->nbr <= 0 || philo->nbr > 2147483647)
		return (-1);
	philo->ttd = ft_atoi(av[2]);
	if (philo->ttd <= 0 || philo->ttd > 2147483647)
		return (-1);
	philo->tte = ft_atoi(av[3]);
	if (philo->tte <= 0 || philo->tte > 2147483647)
		return (-1);
	philo->tts = ft_atoi(av[4]);
	if (philo->tts <= 0 || philo->tts > 2147483647)
		return (-1);
	if (av[5])
	{
		philo->tme = ft_atoi(av[5]);
		if (philo->tme <= 0 || philo->tme > 2147483647)
			return (-1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_philo	philo;

	if ((ac != 5 && ac != 6) || check_if_not_digit(av) == -1
		|| valid_arguments(av, &philo) == -1)
		return (ft_print_fd("Les arguments ne sont pas valides !\n", 2), -1);
	return (0);
}
