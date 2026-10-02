/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:41:04 by pgiorgi           #+#    #+#             */
/*   Updated: 2023/10/26 18:50:17 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_len(int nb)
{
	size_t	i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	if (nb == 0)
	{
		return (0);
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_hexa_low(unsigned int nb)
{
	char		result[30];
	char		*base;
	int			i;
	int			len;

	base = "0123456789abcdef";
	i = 0;
	len = 0;
	if (nb == 0)
	{
		write (1, "0", 1);
		len++;
	}
	while (nb > 0)
	{
		result[i++] = base[(nb % 16)];
		nb /= 16;
	}
	while (i > 0)
	{
		ft_putchar(result[--i]);
		len++;
	}
	return (len);
}

int	ft_hexa_upp(unsigned int nb)
{
	char	result[30];
	char	*base;
	int		i;
	int		len;

	base = "0123456789ABCDEF";
	i = 0;
	len = 0;
	if (nb == 0)
	{
		write (1, "0", 1);
		len++;
	}
	while (nb > 0)
	{
		result[i++] = base[(nb % 16)];
		nb /= 16;
	}
	while (i > 0)
	{
		ft_putchar(result[--i]);
		len++;
	}
	return (len);
}

int	ft_hexa_ptr(void *ptr)
{
	char		result[30];
	char		*base;
	uintptr_t	nb;
	int			i;
	int			len;

	nb = (uintptr_t)ptr;
	base = "0123456789abcdef";
	i = 0;
	len = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	else
		write(1, "0x", 2);
	while (nb > 0)
	{
		result[i++] = base[(nb % 16)];
		nb /= 16;
	}
	while (i > 0)
	{
		ft_putchar(result[--i]);
		len++;
	}
	return (len + 2);
}
