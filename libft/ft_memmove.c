/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruthann <pruth@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:39:26 by pruthann          #+#    #+#             */
/*   Updated: 2020/11/14 15:41:04 by pruthann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*src_true;
	int			i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (dst);
	dest = (char*)dst;
	src_true = (const char*)src;
	if (dest >= src_true)
		while (len)
		{
			dest[len - 1] = src_true[len - 1];
			len--;
		}
	else
		while (len)
		{
			dest[i] = src_true[i];
			len--;
			i++;
		}
	return (dest);
}
