/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsingened.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:31:09 by mfornah           #+#    #+#             */
/*   Updated: 2022/12/02 11:23:36 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * *|MARKER_CURSOR|*
 * 
 * @param num the number to be printed
 * 
 * @return The number of characters printed.
 */
int	ft_print_unsingened(unsigned int num)
{
	unsigned int	count;

	count = 0;
	if (num >= 0 || num <= 2147483647)
	{
		if (num > 9)
		{
			count += ft_printf_putnbr(num / 10);
			count += ft_printf_putnbr(num % 10);
		}
		else
			count += ft_print_putchar(num + '0');
	}
	return (count);
}
