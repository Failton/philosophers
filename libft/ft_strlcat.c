/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruthann <pruth@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 16:26:53 by pruthann          #+#    #+#             */
/*   Updated: 2020/11/15 13:58:27 by pruthann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char			*temp_dst;
	char			*temp_src;
	unsigned int	temp_dstsize;
	unsigned int	len;

	len = ft_strlen(dst) + ft_strlen(src);
	temp_dst = dst;
	temp_src = (char *)src;
	temp_dstsize = dstsize;
	if (dstsize < ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	while (*temp_dst && temp_dstsize)
	{
		temp_dst++;
		temp_dstsize--;
	}
	while (*temp_src && temp_dstsize - 1 && temp_dstsize)
	{
		*temp_dst = *temp_src;
		temp_src++;
		temp_dst++;
		temp_dstsize--;
	}
	*temp_dst = '\0';
	return (len);
}
