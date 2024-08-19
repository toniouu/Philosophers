/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:34:30 by atovoman          #+#    #+#             */
/*   Updated: 2024/08/19 13:58:27 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

struct timeval	*my_get_time()
{
	struct timeval	*tv;

	gettimeofday(tv, NULL);
	tv->tv_sec *= 1000;
	tv->tv_usec /= 1000;
	return (tv);
}
 
