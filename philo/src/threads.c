/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:15:59 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/14 17:20:17 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_philos(t_program *program, pthread_mutex_t *forks)
{
	int			i;
	pthread_t	big_brother;

	i = -1;
	if (pthread_create(&big_brother, NULL, &watching_you, program->philo) != 0)
		philo_clean("Error creating big_brother!", program, forks);
	while (++i < program->philo[0].num_of_philos)
	{
		if (pthread_create(&program->philo[i].thread, NULL, &philo_rotine, \
			&program->philo[i]) != 0)
			philo_clean("Error creating a philosopher!", program, forks);
	}
	i = -1;
	if (pthread_join(big_brother, NULL) != 0)
		philo_clean("Error waiting for big_brother!", program, forks);
	while (++i < program->philo[0].num_of_philos)
	{
		if (pthread_join(program->philo[i].thread, NULL) != 0)
			philo_clean("Error waiting for a philosopher!", program, forks);
	}
}
