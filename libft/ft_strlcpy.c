/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruthann <pruth@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:44:00 by pruthann          #+#    #+#             */
/*   Updated: 2020/11/14 15:45:31 by pruthann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int i;

	i = 0;
	if (!dst)
		return (0);
	if (!dstsize)
		return (ft_strlen(src));
	while (dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
