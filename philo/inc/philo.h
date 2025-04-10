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

# endif

