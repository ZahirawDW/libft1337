/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-mahj <zel-mahj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 17:47:32 by zel-mahj          #+#    #+#             */
/*   Updated: 2026/11/01 08:50:11 by zel-mahj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*subs;

	if (s == NULL)
		return (ft_strdup(""));
	i = ft_strlen(s);
	if (i < start)
		return (ft_strdup(""));
	i = i - start;
	if (i >= len)
		size = len * sizeof(char) + 1;
	else
		size = i * sizeof(char) + 1;
	subs = malloc(size);
	if (subs == NULL)
		return (NULL);
	ft_strlcpy(subs, &s[start], size);
	return (subs);
}
