/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-mahj <zel-mahj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 10:56:29 by zel-mahj          #+#    #+#             */
/*   Updated: 2026/11/01 09:34:56 by zel-mahj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbofint(long n)
{
	long	cp;
	int		b;

	cp = n;
	b = 0;
	if (cp < 0)
		cp = -cp;
	while (cp >= 10)
	{
		cp /= 10;
		b++;
	}
	b++;
	return (b);
}

static char	*nbfill(char *copy, int b, int len, long nb)
{
	copy[len - 1] = '\0';
	len -= 2;
	while (b > 0)
	{
		copy[len] = (nb % 10) + '0';
		nb = nb / 10;
		b--;
		len--;
	}
	return (copy);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		b;
	int		sign;
	char	*copy;
	int		len;

	nb = n;
	sign = 0;
	b = nbofint(nb);
	if (nb < 0)
	{
		nb = -nb;
		sign++;
	}
	len = b * sizeof(char) + sign + 1;
	copy = malloc(len);
	if (copy == NULL)
		return (NULL);
	if (sign == 1)
	{
		copy[0] = '-';
	}
	nbfill(copy, b, len, nb);
	return (copy);
}
