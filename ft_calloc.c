/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-mahj <zel-mahj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 17:18:46 by zel-mahj          #+#    #+#             */
/*   Updated: 2026/10/31 17:36:31 by zel-mahj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	size_t			i;
	size_t			tot;

	i = 0;
	tot = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (tot / size != nmemb)
		return (NULL);
	p = malloc(tot);
	if (p == NULL)
		return (NULL);
	while (i < tot)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
