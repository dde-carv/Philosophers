#include "philo.h"

void	*philo_rotine(void *ptr)
{
	
}

void	*monitor(void *ptr)
{

}

void	start_philos(t_program *program, pthread_mutex_t *forks)
{
	int			i;
	pthread_t	big_brother;

	i = -1;
	if (pthread_create(&big_brother, NULL, &monitor, program->philo) != 0)
		destroy_all(); // ! On error clean all mutex and prints error message
	while (++i < program->philo[i].num_of_philos)
	{
		if (pthread_create(&program->philo[i].thread, NULL, &philo_rotine, &program->philo[i]) != 0)
			destroy_all(); // ! On error clean all mutex and prints error message
	}
	i = -1;
	if (pthread_join(&big_brother, NULL) != 0)
		destroy_all(); // ! On error clean all mutex and prints error message
	while (++i < program->philo[i].num_of_philos)
	{
		if (pthread_join(&program->philo[i].thread, NULL) != 0)
			destroy_all(); // ! On error clean all mutex and prints error message
	}
}