/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:15:12 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/14 17:27:21 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define MAX_PHILO 200

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				is_eating;
	int				count_meals;
	int				*death;
	int				times_to_eat;
	int				num_of_philos;
	size_t			start_time;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*death_lock;
	pthread_mutex_t	*lunch_lock;
	pthread_mutex_t	*print_lock;
}			t_philo;

typedef struct s_program
{
	int				death_flag;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	lunch_lock;
	pthread_mutex_t	print_lock;
	t_philo			*philo;
}			t_program;

/*********************************** Utils ***********************************/

size_t	get_time(void);
int		dead(t_philo *philo);
int		ft_atoi(const char *str);
void	ft_usleep(size_t ms);
void	ft_putendl_fd(char *s, int fd);
void	print_mess(char *str, t_philo *philo, int id);
void	philo_clean(char *str, t_program *program, pthread_mutex_t *forks);

/*********************************** Init ************************************/

void	philos_init(t_philo *philo, t_program *program, pthread_mutex_t \
	*forks, char **av);
void	forks_init(pthread_mutex_t *forks, int num_philos);
void	program_init(t_program *program, t_philo *philo);

/********************************* Threads ***********************************/

void	*watching_you(void *ptr);
void	*philo_rotine(void *ptr);
void	start_philos(t_program *program, pthread_mutex_t *forks);

#endif
