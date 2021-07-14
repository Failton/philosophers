/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruthann <pruth@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:41:16 by pruthann          #+#    #+#             */
/*   Updated: 2020/11/14 15:41:42 by pruthann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		c_true;
	const unsigned char	*src;

	src = (const unsigned char *)s;
	c_true = (unsigned char)c;
	while (n)
	{
		if (*src == c_true)
			return ((void *)src);
		src++;
		n--;
	}
	return (0);
}
