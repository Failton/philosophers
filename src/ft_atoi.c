#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	minus;

	num = 0;
	minus = 2;
	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 45)
		minus = 1;
	if (str[i] == 43)
		minus = 0;
	if (minus == 0 || minus == 1)
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	if (minus == 1)
		num *= -1;
	return (num);
}
