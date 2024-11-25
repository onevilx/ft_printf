/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:32:15 by yaboukir          #+#    #+#             */
/*   Updated: 2024/11/25 16:49:04 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_pf(char f, va_list arg)
{
	int	count;

	count = 0;
	if (f == '%')
		count = count + ft_putchar_pf('%');
	else if (f == '\n')
		count = count + ft_putchar_pf('\n');
	else if (f == 'c')
		count = count + ft_putchar_pf(va_arg(arg, int));
	else if (f == 's')
		count = count + ft_putstr_pf(va_arg(arg, char *));
	else if (f == 'p')
		count = count + ft_putptr_pf(va_arg(arg, void *));
	else if (f == 'u')
		count = count + ft_putuns_pf(va_arg(arg, unsigned int));
	else if (f == 'd' || f == 'i')
		count = count + ft_putnbr_pf(va_arg(arg, int));
	else if (f == 'x' || f == 'X')
		count = count + ft_puthex_pf(va_arg(arg, unsigned int), f);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	arg;

	count = 0;
	va_start(arg, str);
	while (*str != '\0')
	{
		if (write(1, "", 0) < 0)
			return (-1);
		if (*str == '%')
			count = count + format_pf(*(++str), arg);
		else
			count = count + write(1, str, 1);
		str++;
	}
	va_end(arg);
	return (count);
}
