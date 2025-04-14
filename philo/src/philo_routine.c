/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:15:46 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/14 17:22:04 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_think(t_philo *philo)
{
	print_mess("is thinking", philo, philo->id);
}

static void	ft_sleep(t_philo *philo)
{
	print_mess("is sleeping", philo, philo->id);
	ft_usleep(philo->time_to_sleep);
}

static void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_mess("has taken a fork", philo, philo->id);
	if (philo->num_of_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	print_mess("has taken a fork", philo, philo->id);
	philo->is_eating = 1;
	print_mess("is eating", philo, philo->id);
	pthread_mutex_lock(philo->lunch_lock);
	philo->last_meal = get_time();
	philo->count_meals++;
	pthread_mutex_unlock(philo->lunch_lock);
	ft_usleep(philo->time_to_eat);
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

int	dead(t_philo *philo)
{
	pthread_mutex_lock(philo->death_lock);
	if (*philo->death == 1)
		return (pthread_mutex_unlock(philo->death_lock), 1);
	return (pthread_mutex_unlock(philo->death_lock), 0);
}

void	*philo_rotine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!dead(philo))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (ptr);
}
