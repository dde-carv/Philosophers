/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_brother.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:15:31 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/14 17:20:59 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	verify_all_ate(t_philo *philo)
{
	int	i;
	int	finish_eating;

	i = -1;
	finish_eating = 0;
	if (philo[0].times_to_eat == -1)
		return (0);
	while (++i < philo[0].num_of_philos)
	{
		pthread_mutex_lock(philo[0].lunch_lock);
		if (philo[i].count_meals >= philo[i].times_to_eat)
			finish_eating++;
		pthread_mutex_unlock(philo[0].lunch_lock);
	}
	if (finish_eating == philo[0].num_of_philos)
	{
		pthread_mutex_lock(philo[0].death_lock);
		*philo->death = 1;
		return (pthread_mutex_unlock(philo[0].death_lock), 1);
	}
	return (0);
}

static int	is_dead(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->lunch_lock);
	if ((get_time() - philo->last_meal) >= time_to_die && philo->is_eating == 0)
		return (pthread_mutex_unlock(philo->lunch_lock), 1);
	return (pthread_mutex_unlock(philo->lunch_lock), 0);
}

static int	verify_dead(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo[0].num_of_philos)
	{
		if (is_dead(&philo[i], philo[i].time_to_die))
		{
			print_mess("died", &philo[i], philo[i].id);
			pthread_mutex_lock(philo[0].death_lock);
			*philo->death = 1;
			return (pthread_mutex_unlock(philo[0].death_lock), 1);
		}
	}
	return (0);
}

void	*watching_you(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (1)
		if (verify_dead(philo) || verify_all_ate(philo))
			break ;
	return (ptr);
}
