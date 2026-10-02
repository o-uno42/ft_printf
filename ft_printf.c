/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:33:45 by pgiorgi           #+#    #+#             */
/*   Updated: 2023/10/26 12:36:19 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_format(const char format, va_list args)
{
	int	len;

	len = 0;
	if (format == 'i' || format == 'd')
		len += (ft_itoa(va_arg(args, int)));
	else if (format == 'u')
		len += (ft_unsitoa(va_arg(args, unsigned int)));
	else if (format == 's')
		len += (ft_putstr(va_arg(args, char *)));
	else if (format == 'c')
		len += (ft_putchar(va_arg(args, int)));
	else if (format == 'x')
		len += (ft_hexa_low(va_arg(args, unsigned int)));
	else if (format == 'X')
		len += (ft_hexa_upp(va_arg(args, unsigned int)));
	else if (format == 'p')
		len += (ft_hexa_ptr(va_arg(args, void *)));
	else if (format == '%')
	{
		write(1, "%", 1);
		len++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_format(str[i], args);
		}
		else
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
