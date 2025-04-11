#include "philo.h"

static int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	check_args(char **av)
{
	if (ft_atoi(av[1]) > MAX_PHILO || ft_atoi(av[1]) <= 0 || !ft_isnumber(av[1]))
		return (ft_putendl_fd("Invalid number of philosophers!", 2), 0);
	if (ft_atoi(av[2]) <= 0 || !ft_isnumber(av[2]))
		return (ft_putendl_fd("Invalid time to die!", 2), 0);
	if (ft_atoi(av[3]) <= 0 || !ft_isnumber(av[3]))
		return (ft_putendl_fd("Invalid time to eat!", 2), 0);
	if (ft_atoi(av[4]) <= 0 || !ft_isnumber(av[4]))
		return (ft_putendl_fd("Invalid time to sleep!", 2), 0);
	if (av[5] && (ft_atoi(av[5]) <= 0 || !ft_isnumber(av[5])))
		return (ft_putendl_fd("Invalid number of times each philosopher must eat!", 2), 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_program		program;
	t_philo			philos[MAX_PHILO];
	pthread_mutex_t	forks[MAX_PHILO];

	if (ac != 5 && ac != 6)
		return (ft_putendl_fd("Syntax error!\n./philo number_of_philosophers time_to_die time_to_eat time_to_sleep\nor\n./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]", 2), 1);
	if (!check_args(av))
		return (1);
	program_init(&program, philos);
	forks_init(forks, ft_atoi(av[1]));
	philos_init(philos, &program, forks, av);
	start_philos(&program, forks);
}
