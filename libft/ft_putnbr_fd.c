/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruthann <pruth@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 16:25:36 by pruthann          #+#    #+#             */
/*   Updated: 2020/11/14 16:25:58 by pruthann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char sign;

	if (n >= 10 || n <= -10)
	{
		if (n <= -10)
			sign = -(n % 10) + 48;
		else
			sign = n % 10 + 48;
		ft_putnbr_fd(n / 10, fd);
		write(fd, &sign, 1);
	}
	else	if (n < 0)
	{
		sign = -n + 48;
		write(fd, &"-", 1);
		write(fd, &sign, 1);
	}
	else
	{
		sign = n + 48;
		write(fd, &sign, 1);
	}
}
