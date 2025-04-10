#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	len;
	int	neg;
	int	nb;

	len = 0;
	neg = 1;
	nb = 0;
	while (str[len] == 12 || str[len] == 10 || str[len] == 13
		|| str[len] == 9 || str[len] == 11 || str[len] == 32)
		len++;
	if (str[len] == 43)
		len++;
	else if (str[len] == 45)
	{
		neg *= -1;
		len++;
	}
	while (ft_isdigit(str[len]))
	{
		nb = (nb * 10) + (str[len] - 48);
		len++;
	}
	nb = nb * neg;
	return (nb);
}

static void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}