#include "philo.h"

static t_philos	*listnew(t_settings *settings, int no)
{
	t_philos *philo;

	philo = malloc(sizeof(t_philos));
	if (philo == NULL)
		return(NULL);
	philo->no = no;
	philo->eat_counter = 0;
	philo->died = 0;
	philo->settings = settings;
	pthread_mutex_init(&(philo->fork), NULL);
	philo->next = NULL;
	return(philo);
}

static int		listadd(t_philos **philos, t_settings *settings, int no)
{
	t_philos *temp;

	temp = *philos;
	if (*philos != NULL)
	{
		while ((*philos)->next != NULL)
			*philos = (*philos)->next;
		(*philos)->next = listnew(settings, no);
		if ((*philos)->next == NULL)
			return(1);
		*philos = temp;
	}
	else
		*philos = listnew(settings, no);
	if (*philos == NULL)
		return(1);
	return(0);
}

static void		circle_list(t_philos *philos)
{
	t_philos *temp;

	temp = philos;
	while (philos->next != NULL)
		philos = philos->next;
	philos->next = temp;
}

int				set_philos(t_philos **philos, t_settings *settings)
{
	int i;

	i = 0;
	while (i < settings->num_philo)
	{
		if (listadd(philos, settings, i + 1) == 1)
			return (1);
		i++;
	}
	circle_list(*philos);
	return(0);
}
