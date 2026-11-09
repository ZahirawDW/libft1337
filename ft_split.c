/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-mahj <zel-mahj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 17:51:20 by zel-mahj          #+#    #+#             */
/*   Updated: 2026/11/07 16:09:27 by zel-mahj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words(char const *s, char c)
{
	int		i;
	int		wod;

	i = 0;
	wod = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			wod++;
		i++;
	}
	return (wod);
}

static char	*eachstr(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (ft_substr(s, 0, i));
}

static char	**free_all(char **strings, int j)
{
	while (j >= 0)
	{
		free(strings[j]);
		j--;
	}
	free(strings);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**strings;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	strings = malloc((words(s, c) + 1) * sizeof(char *));
	if (strings == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			strings[j] = eachstr(&s[i], c);
			if (strings[j] == NULL)
				return (free_all(strings, j));
			j++;
		}
		i++;
	}
	strings[j] = NULL;
	return (strings);
}
