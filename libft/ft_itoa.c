/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruthann <pruth@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:55:48 by pruthann          #+#    #+#             */
/*   Updated: 2020/11/14 15:56:27 by pruthann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_str(char *str, int n, int i)
{
	char	sign;

	if (n >= 10 || n <= -10)
	{
		if (n <= -10)
			sign = -(n % 10) + 48;
		else
			sign = n % 10 + 48;
		ft_putnbr_str(str, n / 10, i + 1);
		str[i] = sign;
	}
	else	if (n < 0)
	{
		sign = -n + 48;
		str[i] = sign;
		str[i + 1] = '-';
	}
	else
	{
		sign = n + 48;
		str[i] = sign;
	}
}

static int	ft_intlen(int n)
{
	int len;

	len = 1;
	if (n < 0)
		len++;
	while (n >= 10 || n <= -10)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*str;
	char	temp;
	int		temp_len;

	i = 0;
	len = ft_intlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	ft_putnbr_str(str, n, 0);
	temp_len = len;
	len = len / 2;
	while (len)
	{
		temp = str[temp_len - 1];
		str[temp_len - 1] = str[i];
		str[i] = temp;
		temp_len--;
		len--;
		i++;
	}
	str[ft_intlen(n)] = '\0';
	return (str);
}
