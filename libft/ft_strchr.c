/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruthann <pruth@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 16:28:23 by pruthann          #+#    #+#             */
/*   Updated: 2020/11/14 16:28:34 by pruthann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char smbl;
	char *str;

	smbl = (char)c;
	str = (char*)s;
	while (*str)
	{
		if (*str == smbl)
			return (str);
		str++;
	}
	if (*str == smbl)
		return (str);
	return (0);
}
