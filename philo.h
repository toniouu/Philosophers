/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:13:27 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/15 11:44:53 by atovoman         ###   ########.fr       */
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
# include "colors.h"

typedef pthread_mutex_t	t_mtx;

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}	t_fork;

typedef struct s_philo
{
	int				id;
	pthread_t		philo;
	t_fork			*left;
	t_fork			*right;
}	t_philo;

typedef struct s_prog
{
	long	nbr;
	long	ttd;
	long	tte;
	long	tts;
	long	limits;
	t_philo	*philos;
	t_fork	*forks;
}	t_prog;

void	print_error(char *error);

int		ft_is_digit(char c);
int		check_if_not_digit(char **av);

long	ft_atoi(char *nbr);

#endif