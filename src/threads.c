#include "philo.h"

static void	*philosopher(void *arg)
{
	t_philos	*philos;

	philos = (t_philos *)arg;
	pthread_detach(philos->thread);
	philos->last_eat = timestamp(philos);
	if (philos->no % 2 == 0)
		usleep(philos->settings->time_eat / 2);
	while (philos->eat_counter != philos->settings->num_eat)
	{
		pthread_mutex_lock(&(philos->fork));
		print_mtx(philos, "has taken a fork");
		pthread_mutex_lock(&(philos->next->fork));
		print_mtx(philos, "has taken a fork");
		philos->last_eat = timestamp(philos);
		print_mtx(philos, "is eating");
		usleep(philos->settings->time_eat);
		pthread_mutex_unlock(&(philos->fork));
		pthread_mutex_unlock(&(philos->next->fork));
		philos->eat_counter++;
		print_mtx(philos, "is sleeping");
		usleep(philos->settings->time_sleep);
		print_mtx(philos, "is thinking");
	}
	return (NULL);
}

int	do_threads(t_philos *philos, t_settings *settings)
{
	int	i;

	i = 0;
	gettimeofday(&(settings->start_time), NULL);
	while (i < philos->settings->num_philo)
	{
		if (pthread_create(&(philos->thread), NULL, philosopher, philos) != 0)
		{
			printf("%s", ERROR);
			return (1);
		}
		philos = philos->next;
		i++;
	}
	return (0);
}
