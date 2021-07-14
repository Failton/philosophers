/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruthann <pruthann@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:16:47 by pruthann          #+#    #+#             */
/*   Updated: 2020/11/14 15:17:18 by pruthann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*str;
	const unsigned char	*src_true;
	unsigned char		sign;

	str = dst;
	src_true = src;
	sign = (unsigned char)c;
	while (n)
	{
		*str = *src_true;
		if (*src_true == sign)
			return (str + 1);
		n--;
		src_true++;
		str++;
	}
	return (0);
}
