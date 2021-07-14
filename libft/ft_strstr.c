/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruthann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:36:40 by pruthann          #+#    #+#             */
/*   Updated: 2020/07/26 20:36:22 by pruthann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char *temp_str;
	char *temp_to_find;

	if (!(*to_find))
		return (str);
	temp_to_find = to_find;
	while (*str)
	{
		temp_str = str;
		while (*(str++) == *(to_find++))
		{
			if (!(*to_find))
				return (temp_str);
			if (!(*str))
				return (0);
		}
		to_find = temp_to_find;
	}
	return (0);
}
