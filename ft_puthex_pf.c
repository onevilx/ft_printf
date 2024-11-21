/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:02:37 by yaboukir          #+#    #+#             */
/*   Updated: 2024/11/21 00:34:53 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_pf(unsigned int n, const char f)
{
	int		count;
	char	num;

	count = 0;
	if (n >= 16)
	{
		count = count + ft_puthex_pf((n / 16), f);
		count = count + ft_puthex_pf((n % 16), f);
	}
	else
	{
		if (n <= 9)
			num = n + 48;
		else
		{
			if (f == 'x')
				num = n - 10 + 97;
			else if (f == 'X')
				num = n - 10 + 65;
		}
		count = count + write(1, &num, 1);
	}
	return (count);
}
