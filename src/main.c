#include "philo.h"

int	checker(t_philos *philos)
{
	int			eat;
	long int	now;

	eat = 0;
	while (eat != philos->settings->num_philo)
	{
		if (philos->eat_counter == philos->settings->num_eat)
			eat++;
		else
			eat = 0;
		now = timestamp(philos);
		if (now - philos->last_eat > philos->settings->time_die)
		{
			pthread_mutex_lock(&(philos->settings->print_mtx));
			printf("%ld %d died\n", timestamp(philos), philos->no);
			return (1);
		}
		philos = philos->next;
	}
	return (1);
}

int	freesher(t_philos *philos)
{
	t_philos	*prev;

	while (philos->no != philos->settings->num_philo)
	{
		usleep(3000);
		pthread_mutex_destroy(&(philos->fork));
		prev = philos;
		philos = philos->next;
		free(prev);
	}
	usleep(3000);
	pthread_mutex_destroy(&(philos->fork));
	pthread_mutex_destroy(&(philos->settings->print_mtx));
	free(philos);
	return (0);
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
		if (parcer_error == 1)
			printf("%s", INVALID_ARGS);
		else
			printf("%s", ERROR);
		return (1);
	}
	if (set_philos(&philos, &settings))
		return (1);
	if (do_threads(philos, &settings))
		return (1);
	checker(philos);
	freesher(philos);
	return (0);
}
