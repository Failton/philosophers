/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruthann <pruth@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:51:12 by pruthann          #+#    #+#             */
/*   Updated: 2020/11/14 15:52:37 by pruthann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char sign, char const *set)
{
	int i;

	i = 0;
	while (set[i] != '\0')
	{
		if (sign == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_f_pos(char const *s1, char const *set)
{
	int i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_inset(s1[i], set) == 0)
			return (i);
		i++;
	}
	return (i);
}

static int	ft_s_pos(char const *s1, char const *set)
{
	int len;

	len = ft_strlen(s1);
	while (len)
	{
		if (ft_inset(s1[len - 1], set) == 0)
			return (len - 1);
		len--;
	}
	return (len);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		f_pos;
	int		s_pos;
	char	*str;

	i = 0;
	if (!s1)
		return (0);
	f_pos = ft_f_pos(s1, set);
	s_pos = ft_s_pos(s1, set);
	if (s_pos - f_pos < 0)
		str = malloc(sizeof(*str) * 1);
	else
		str = malloc(sizeof(*str) * (s_pos - f_pos + 2));
	if (str == 0)
		return (0);
	while (f_pos <= s_pos)
	{
		str[i] = s1[f_pos];
		i++;
		f_pos++;
	}
	str[i] = '\0';
	return (str);
}
