/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruthann <pruth@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:52:44 by pruthann          #+#    #+#             */
/*   Updated: 2020/11/15 14:40:04 by pruthann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_arraysize(char const *s, char c)
{
	int i;
	int n;

	i = 0;
	n = 1;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			n++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (n);
}

static int	ft_allocword(char const *s, char c, char ***words)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		while (s[j] != c && s[j] != '\0')
			j++;
		words[0][k] = malloc(sizeof(char) * (j - i + 1));
		i = j;
		if (words[0][k] == 0)
			return (k);
		k++;
	}
	words[0][k] = NULL;
	return (-1);
}

static int	ft_alloc(char const *s, char c, char ***words)
{
	int alloc;

	if (!s)
		return (0);
	*words = malloc(sizeof(char*) * (ft_arraysize(s, c)));
	if (words == 0)
	{
		free(*words);
		return (0);
	}
	alloc = ft_allocword(s, c, words);
	if (alloc >= 0)
	{
		while (alloc <= 0)
		{
			free(words[0][alloc]);
			alloc--;
		}
		free(*words);
		return (0);
	}
	return (1);
}

char		**ft_split(char const *s, char c)
{
	char	**words;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	s = ft_strtrim(s, &c);
	if (ft_alloc(s, c, &words) == 0)
		return (NULL);
	while (s[i] != '\0')
	{
		k = 0;
		while (s[i] != c && s[i] != '\0')
			words[j][k++] = s[i++];
		words[j][k] = '\0';
		j++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	free((void*)s);
	return (words);
}
