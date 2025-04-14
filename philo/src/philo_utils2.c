/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:15:54 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/14 17:22:17 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_mess(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->print_lock);
	time = get_time() - philo->start_time;
	if (!dead(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->print_lock);
}

void	philo_clean(char *str, t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = -1;
	if (str)
		ft_putendl_fd(str, 2);
	pthread_mutex_destroy(&program->death_lock);
	pthread_mutex_destroy(&program->lunch_lock);
	pthread_mutex_destroy(&program->print_lock);
	while (++i < program->philo[0].num_of_philos)
		pthread_mutex_destroy(&forks[i]);
}

void	ft_usleep(size_t ms)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < ms)
		usleep(500);
	return ;
}

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_putendl_fd("gettimeofday() function error!", 2);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
