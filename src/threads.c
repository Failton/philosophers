#include "philo.h"

static void	*monitor(void *arg)
{
	t_philos	*philos;
	long int	now;

	philos = (t_philos *)arg;
	pthread_detach(philos->monitor);
	while (1 == 1)
	{
		now = timestamp(philos);
		if (philos->eat_counter == philos->settings->num_eat)
			break;
		if (now - philos->last_eat > philos->settings->time_die)
		{
			philos->died = 1;
			break;
		}
	}
	return (NULL);
}

static void	*philosopher(void *arg)
{
	t_philos *philos;

	philos = (t_philos *)arg;
	pthread_detach(philos->thread);
	philos->last_eat = timestamp(philos);
	pthread_create(&(philos->monitor), NULL, monitor, philos);
	if (philos->no % 2 == 0)
		ft_usleep(philos, philos->settings->time_eat / 2);
	while (1 == 1)
	{
		pthread_mutex_lock(&(philos->fork));
		print_mtx(philos, "has taken a left fork");
		pthread_mutex_lock(&(philos->next->fork));
		print_mtx(philos, "has taken a right fork");
		philos->last_eat = timestamp(philos);
		print_mtx(philos, "is eating");
		ft_usleep(philos, philos->settings->time_eat);
		pthread_mutex_unlock(&(philos->fork));
		pthread_mutex_unlock(&(philos->next->fork));
		philos->eat_counter++;
		if (philos->eat_counter == philos->settings->num_eat)
			break;
		print_mtx(philos, "is sleeping");
		ft_usleep(philos, philos->settings->time_sleep);
		print_mtx(philos, "is thinking");
	}
	return (NULL);
}

void		do_threads(t_philos *philos, t_settings *settings)
{
	int i;

	i = 0;
	gettimeofday(&(settings->start_time), NULL);
	while (i < philos->settings->num_philo)
	{
		pthread_create(&(philos->thread), NULL, philosopher, philos);
		philos = philos->next;
		i++;
	}
}
