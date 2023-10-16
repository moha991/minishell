/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkparam.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:30:53 by mfornah           #+#    #+#             */
/*   Updated: 2022/11/27 18:55:45 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * It checks the parameter after the % sign and prints it out
 * @param input the string that is being parsed
 * @param i the index of the input string
 * @param count the number of characters printed
 * @param  `const char *input` - the string that is being parsed
 * 
 * @return The number of characters printed.
 */
int	ft_checkparam(const char *input, int i, int count, va_list (pa))
{
	if (input[i + 1] == 'c')
		count += ft_print_putchar(va_arg(pa, int));
	if (input[i + 1] == 's')
		count += ft_print_putstr(va_arg(pa, char *));
	if (input[i + 1] == 'p')
		count += ft_hexpointer(va_arg(pa, size_t));
	if (input[i + 1] == 'd' || input[i + 1] == 'i')
		count += ft_printf_putnbr(va_arg(pa, int));
	if (input[i + 1] == 'u')
		count += ft_print_unsingened(va_arg(pa, unsigned int));
	if (input[i + 1] == 'x')
		count += ft_putnbr_base_uns(va_arg(pa, int), HEXADECIMAL_MIN);
	if (input[i + 1] == 'X')
		count += ft_putnbr_base_uns(va_arg(pa, int), HEXADECIMAL_MA);
	if (input[i + 1] == '%')
		count += write(1, "%", 1);
	return (count);
}
