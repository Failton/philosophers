#include "philo.h"

int	checker(t_philos *philos)
{
	int eat;

	eat = 0;
	while (eat != philos->settings->num_philo)
	{
		if (philos->eat_counter == philos->settings->num_eat)
			eat++;
		else
			eat = 0;
		if (philos->died == 1)
		{
			pthread_mutex_lock(&(philos->settings->print_mtx));
			printf("%ld %d died\n", timestamp(philos), philos->no);
			return(1);
		}
		philos = philos->next;
	}
	return(1);
}

int	freesher(t_philos *philos)
{
	t_philos *prev;

	while (philos->no != philos->settings->num_philo)
	{
		usleep(100000);
		pthread_mutex_destroy(&(philos->fork));
		prev = philos;
		philos = philos->next;
		free(prev);
	}
	usleep(100000);
	pthread_mutex_destroy(&(philos->fork));
	pthread_mutex_destroy(&(philos->settings->print_mtx));
	free(philos);
	return(0);
}

int	main(int argc, char **argv)
{
	t_philos	*philos;
	t_settings	settings;
	int			parcer_error;

	philos = NULL;
	parcer_error = parcer(argc, argv, &settings);
	if (parcer_error != 0)
	{
		printf("%s", INVALID_ARGS);
		return (1);
	}
	set_philos(&philos, &settings);
	do_threads(philos, &settings);
	checker(philos);
	freesher(philos);
	return (0);
}
