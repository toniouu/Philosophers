/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:13:27 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/13 16:49:04 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int	nbr;
	int	ttd;
	int	tte;
	int	tts;
	int	tme;
}	t_philo;


int		ft_strlen(char *s);
int		ft_is_digit(char c);
int		check_if_not_digit(char **av);

long	ft_atoi(char *nbr);

void	ft_print_fd(char *s, int fd);

#endif