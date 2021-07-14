/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruthann <pruthann@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:14:46 by pruthann          #+#    #+#             */
/*   Updated: 2020/11/14 15:16:13 by pruthann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int			i;
	char		*str;
	const char	*src2;

	if (dst == NULL && src == NULL)
		return (dst);
	i = 0;
	str = dst;
	src2 = src;
	while (n)
	{
		str[i] = src2[i];
		i++;
		n--;
	}
	return (str);
}
