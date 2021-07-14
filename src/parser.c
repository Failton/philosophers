#include "philo.h"

static int	check_argv(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != 0)
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (1);
			j++;
		}
		i++;
	}
	return(0);
}

int			parcer(int argc, char **argv, t_settings *settings)
{
	if (argc != 5 && argc != 6)
		return(1);
	if (check_argv(argv) != 0)
		return(1);
	settings->num_philo = ft_atoi(argv[1]);
	settings->time_die = ft_atoi(argv[2]);
	settings->time_eat = ft_atoi(argv[3]);
	settings->time_sleep = ft_atoi(argv[4]);
	pthread_mutex_init(&(settings->print_mtx), NULL);
	if (settings->num_philo < 1 || settings->time_die < 1 || settings->time_eat < 1 || settings->time_sleep < 1)
		return(1);
	if (argc == 6)
	{
		settings->num_eat = ft_atoi(argv[5]);
		if (settings->num_eat < 1)
			return(1);
	}
	else
		settings->num_eat = -1;
	return (0);
}
