/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-mahj <zel-mahj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:14:13 by zel-mahj          #+#    #+#             */
/*   Updated: 2026/11/07 11:57:35 by zel-mahj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*nullhandle(char const *s1, char const *s2)
{
	char	*p;

	p = NULL;
	if (s1 == NULL && s2 == NULL)
		p = ft_strdup("");
	if (s1 == NULL && s2 != NULL)
		p = ft_strdup(s2);
	if (s1 != NULL && s2 == NULL)
		p = ft_strdup(s1);
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*nstr;

	if (s1 == NULL || s2 == NULL)
		return (nullhandle(s1, s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	nstr = malloc((len1 + len2) * sizeof(char) + 1);
	if (nstr == NULL)
		return (NULL);
	ft_strlcpy(nstr, s1, len1 + 1);
	len2 = 0;
	while (s2[len2])
	{
		nstr[len1] = s2[len2];
		len1++;
		len2++;
	}
	nstr[len1] = '\0';
	return (nstr);
}
