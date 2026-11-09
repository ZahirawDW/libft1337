/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-mahj <zel-mahj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 16:08:52 by zel-mahj          #+#    #+#             */
/*   Updated: 2026/10/31 17:12:20 by zel-mahj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	space(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] && (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r')))
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	long	n;
	long	temp;
	int		i;
	int		sign;

	i = space(nptr);
	n = 0;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		temp = n;
		n = (nptr[i] - '0') + (n * 10);
		if (temp > n && sign == -1)
			return (0);
		else if (temp > n)
			return (-1);
		i++;
	}
	return (n * sign);
}
