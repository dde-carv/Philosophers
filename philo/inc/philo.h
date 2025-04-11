#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

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
	int				num_of_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			times_to_eat;
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

int		ft_atoi(const char *str);
void	ft_putendl_fd(char *s, int fd);
void	philos_init(t_philo *philo, t_program *program, pthread_mutex_t *forks, char **av);
void	forks_init(pthread_mutex_t *forks, int num_philos);
void	program_init(t_program *program, t_philo *philo);

# endif
