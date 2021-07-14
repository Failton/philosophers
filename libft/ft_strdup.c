/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruthann <pruth@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 16:51:53 by pruthann          #+#    #+#             */
/*   Updated: 2020/11/14 16:52:42 by pruthann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*newsrc;
	char	*temp;
	int		len;

	len = 0;
	while (src[len] != '\0')
		len++;
	newsrc = malloc((len + 1) * sizeof(*src));
	if (newsrc == 0)
		return (NULL);
	temp = newsrc;
	while (*src)
	{
		*newsrc = *src;
		newsrc++;
		src++;
	}
	*newsrc = '\0';
	return (temp);
}
