/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:13:18 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/15 12:12:10 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	valid_arguments(char **av, t_prog *prog)
{
	prog->nbr = ft_atoi(av[1]);
	if (prog->nbr <= 0 || prog->nbr > 2147483647)
		return (-1);
	prog->ttd = ft_atoi(av[2]);
	if (prog->ttd <= 0 || prog->ttd > 2147483647)
		return (-1);
	prog->tte = ft_atoi(av[3]);
	if (prog->tte <= 0 || prog->tte > 2147483647)
		return (-1);
	prog->tts = ft_atoi(av[4]);
	if (prog->tts <= 0 || prog->tts > 2147483647)
		return (-1);
	if (av[5])
	{
		prog->limits = ft_atoi(av[5]);
		if (prog->limits <= 0 || prog->limits > 2147483647)
			return (-1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_prog	prog;

	if ((ac != 5 && ac != 6) || check_if_not_digit(av) == -1
		|| valid_arguments(av, &prog) == -1)
		return (print_error("Les arguments ne sont pas valides !"), -1);
	



	return (0);
}