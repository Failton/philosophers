/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruthann <pruth@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:46:33 by pruthann          #+#    #+#             */
/*   Updated: 2020/11/14 15:47:58 by pruthann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	str = malloc(sizeof(*str) * (len + 1));
	if (str == 0)
		return (0);
	if (start >= ft_strlen(s))
		str[i] = '\0';
	else
		while (s[start] && len != i)
		{
			str[i] = s[start];
			i++;
			start++;
		}
	str[i] = '\0';
	return (str);
}
