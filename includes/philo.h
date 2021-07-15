#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>

# define INVALID_ARGS "Error: Invalid args"
# define ERROR "Error while running program..."

typedef struct s_settings
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_eat;
	pthread_mutex_t	print_mtx;
	long int		timest;
	struct timeval	start_time;
}					t_settings;

typedef struct s_philos
{
	int				no;
	pthread_t		thread;
	pthread_t		monitor;
	pthread_mutex_t	fork;
	int				died;
	int				eat_counter;
	long int		last_eat;
	struct s_philos	*next;
	t_settings		*settings;
}					t_philos;

int					parcer(int argc, char **argv, t_settings *base);
int					set_philos(t_philos **philos, t_settings *settings);
int					do_threads(t_philos *philos, t_settings *settings);
long int			timestamp(t_philos *philos);
void				print_mtx(t_philos *philos, char *msg);
int					ft_atoi(const char *str);
#endif
