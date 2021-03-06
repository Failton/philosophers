#include "philo.h"

long int	timestamp(t_philos *philos)
{
	long int		time;
	struct timeval	now;

	time = 0;
	gettimeofday(&now, NULL);
	time = (now.tv_sec - philos->settings->start_time.tv_sec) * 1000
		+ (now.tv_usec - philos->settings->start_time.tv_usec) / 1000;
	return (time);
}

void	print_mtx(t_philos *philos, char *msg)
{
	pthread_mutex_lock(&(philos->settings->print_mtx));
	printf("%ld %d %s\n", timestamp(philos), philos->no, msg);
	pthread_mutex_unlock(&(philos->settings->print_mtx));
}
