/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:17:40 by pgiorgi           #+#    #+#             */
/*   Updated: 2023/11/09 11:17:44 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf(const char *str, ...);
int	ft_format(const char str, va_list args);
int	ft_itoa(int n);
int	ft_unsitoa(unsigned int n);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_hexa_low(unsigned int nb);
int	ft_hexa_upp(unsigned int nb);
int	ft_hexa_ptr(void *ptr);
int	ft_strlen(const char *str);

#endif
