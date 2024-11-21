/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:37:14 by yaboukir          #+#    #+#             */
/*   Updated: 2024/11/21 00:59:28 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuns_pf(unsigned int n)
{
	int		count;
	char	num;

	count = 0;
	if (n > 9)
	{
		count = count + ft_putuns_pf(n / 10);
		count = count + ft_putuns_pf(n % 10);
	}
	if (n >= 0 && n <= 9)
	{
		num = n + 48;
		count = count + write(1, &num, 1);
	}
	return (count);
}
