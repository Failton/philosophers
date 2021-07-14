/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruthann <pruthann@student.21-school.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:56:27 by pruthann          #+#    #+#             */
/*   Updated: 2020/11/14 15:12:58 by pruthann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*str;

	i = 0;
	str = b;
	while (len != 0)
	{
		str[i] = c;
		len--;
		i++;
	}
	return (b);
}
