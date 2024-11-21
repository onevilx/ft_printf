/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:55:40 by yaboukir          #+#    #+#             */
/*   Updated: 2024/11/21 20:30:04 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>  //this lib just for testing the program / it is forbidden ;)
# include <unistd.h>
# include <stdlib.h>

int	ft_putnbr_pf(int n);
int	ft_putchar_pf(char c);
int	ft_putstr_pf(char *str);
int	ft_putptr_pf(void *ptr);
int	ft_putuns_pf(unsigned int n);
int	ft_printf(const char *str, ...);
int	ft_puthex_pf(unsigned int n, const char f);

#endif
