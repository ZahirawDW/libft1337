/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-mahj <zel-mahj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:32:18 by zel-mahj          #+#    #+#             */
/*   Updated: 2026/11/07 11:57:47 by zel-mahj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_srclen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static size_t	ft_dstlen(const char *s, size_t size)
{
	size_t	i;

	i = 0;
	while (size > i && s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	j;
	size_t	i;

	dst_len = ft_dstlen(dst, size);
	src_len = ft_srclen(src);
	i = 0;
	j = dst_len;
	if (size == 0 || size <= j)
		return (size + src_len);
	while (j < size - 1 && src[i] != '\0')
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dst_len + src_len);
}
