/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-mahj <zel-mahj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 17:50:44 by zel-mahj          #+#    #+#             */
/*   Updated: 2026/11/01 09:01:11 by zel-mahj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_forward(char const *s1, char const *set)
{
	int		i;
	char	*p;

	i = 0;
	while (s1[i])
	{
		p = ft_strchr(set, s1[i]);
		if (p == NULL)
			return (i);
		i++;
	}
	return (i);
}

static int	ft_backward(char const *s1, char const *set)
{
	int		i;
	char	*p;

	i = 0;
	while (s1[i])
		i++;
	i--;
	while (i >= 0)
	{
		p = ft_strchr(set, s1[i]);
		if (p == NULL)
			return (i);
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*p;

	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(s1));
	start = ft_forward(s1, set);
	end = ft_backward(s1, set);
	if (start > end)
		return (ft_strdup(""));
	p = ft_substr(s1, start, end - start + 1);
	return (p);
}
