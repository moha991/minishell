/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:54:35 by mfornah           #+#    #+#             */
/*   Updated: 2022/12/01 16:52:24 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * It prints an integer
 * 
 * @param n The number to be printed.
 * 
 * @return The number of characters printed.
 */
int	ft_printf_putnbr(int n)
{
	unsigned int	num;

	num = 0;
	if (n > -2147483648 || n <= 2147483647)
	{
		if (n == -2147483648)
		{
			num += ft_print_putstr("-2");
			num += ft_printf_putnbr(147483648);
		}
		else if (n > 9)
		{
			num += ft_printf_putnbr(n / 10);
			num += ft_printf_putnbr(n % 10);
		}
		else if (n < 0)
		{
			n = -n;
			num += ft_print_putchar('-');
			num += ft_printf_putnbr(n);
		}
		else
			num += ft_print_putchar(n + '0');
	}
	return (num);
}
