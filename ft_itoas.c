/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:09:27 by pgiorgi           #+#    #+#             */
/*   Updated: 2023/10/16 17:55:10 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count(long long i)
{
	int	nb;

	nb = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		i = -i;
		nb++;
	}
	while (i > 0)
	{
		i = i / 10;
		nb++;
	}
	return (nb);
}

int	ft_itoa(int n)
{
	char		result[12];
	size_t		len;
	long long	nb;

	len = count(n);
	nb = (long long) n;
	if (nb == 0)
		result[0] = '0';
	if (nb < 0)
	{
		result[0] = '-';
		nb = -nb;
	}
	result [len] = '\0';
	while (nb > 0)
	{
		result[--len] = '0' + (nb % 10);
		nb = nb / 10;
	}
	ft_putstr(result);
	len = ft_strlen(result);
	return (len);
}

int	ft_unsitoa(unsigned int n)
{
	char		*result;
	size_t		len;
	long long	nb;

	len = count(n);
	nb = (long long) n;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	if (nb == 0)
		result[0] = '0';
	result [len] = '\0';
	while (nb > 0)
	{
		result[--len] = '0' + (nb % 10);
		nb = nb / 10;
	}
	ft_putstr(result);
	len = ft_strlen(result);
	free(result);
	return (len);
}
