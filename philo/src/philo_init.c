/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:15:41 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/14 17:16:47 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	input_init(t_philo *philo, char **av)
{
	philo->num_of_philos = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->times_to_eat = ft_atoi(av[5]);
	else
		philo->times_to_eat = -1;
}

void	philos_init(t_philo *philo, t_program *program, pthread_mutex_t *forks, \
	char **av)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(av[1]))
	{
		input_init(&philo[i], av);
		philo[i].id = i + 1;
		philo[i].is_eating = 0;
		philo[i].count_meals = 0;
		philo[i].death = &program->death_flag;
		philo[i].start_time = get_time();
		philo[i].last_meal = get_time();
		philo[i].death_lock = &program->death_lock;
		philo[i].lunch_lock = &program->lunch_lock;
		philo[i].print_lock = &program->print_lock;
		philo[i].l_fork = &forks[i];
		if (i == 0)
			philo[i].r_fork = &forks[philo[0].num_of_philos - 1];
		else
			philo[i].r_fork = &forks[i - 1];
	}
}

void	forks_init(pthread_mutex_t *forks, int num_philos)
{
	int	i;

	i = -1;
	while (++i < num_philos)
		pthread_mutex_init(&forks[i], NULL);
}

void	program_init(t_program *program, t_philo *philo)
{
	program->philo = philo;
	program->death_flag = 0;
	pthread_mutex_init(&program->death_lock, NULL);
	pthread_mutex_init(&program->lunch_lock, NULL);
	pthread_mutex_init(&program->print_lock, NULL);
}
