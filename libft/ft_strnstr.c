/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruthann <pruth@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 16:29:14 by pruthann          #+#    #+#             */
/*   Updated: 2020/11/14 16:29:56 by pruthann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*temp_haystack;
	char	*temp_needle;
	char	*haystack_iter;
	int		temp_len;

	if (!(*needle))
		return ((char *)haystack);
	temp_needle = (char *)needle;
	haystack_iter = (char *)haystack;
	while (*haystack_iter && len)
	{
		temp_len = len;
		temp_haystack = haystack_iter;
		while (*(temp_haystack++) == *(temp_needle++) && len)
		{
			if (!(*temp_needle))
				return (haystack_iter);
			len--;
		}
		temp_needle = (char *)needle;
		haystack_iter++;
		len = temp_len;
		len--;
	}
	return (0);
}
