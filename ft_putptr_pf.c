/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:48:14 by yaboukir          #+#    #+#             */
/*   Updated: 2024/11/21 00:58:02 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printptrpf(unsigned long n)
{
	int		count;
	char	num;

	count = 0;
	if (n >= 16)
	{
		count = count + ft_printptrpf(n / 16);
		count = count + ft_printptrpf(n % 16);
	}
	else
	{
		if (n <= 9)
			num = n + 48;
		else
			num = n - 10 + 97;
		count = count + write(1, &num, 1);
	}
	return (count);
}

int	ft_putptr_pf(void *ptr)
{
	int				len;
	unsigned long	n;

	len = 2;
	n = (unsigned long)ptr;
	write (1, "0x", 2);
	return (ft_printptrpf(n) + len);
}
