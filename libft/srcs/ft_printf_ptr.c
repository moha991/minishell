/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 08:20:33 by mfornah           #+#    #+#             */
/*   Updated: 2022/11/30 18:29:04 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * It prints a hexadecimal number
 * 
 * @param H The number to be converted to hexadecimal.
 * 
 * @return The number of characters printed.
 */
static	int	ft_hexa(size_t H)
{
	static int	tam;
	char		*base;

	base = HEXADECIMAL_MIN;
	tam = 0;
	if (H >= 16)
	{
		ft_hexa(H / 16);
		H %= 16;
	}
	tam++;
	ft_print_putchar(base[H]);
	return (tam);
}

/**
 * It prints a pointer
 * 
 * @param ptr the pointer to print
 * 
 * @return The number of characters printed.
 */
int	ft_printf_ptr(void *ptr)
{
	int		n1;
	size_t	nbr;

	nbr = (size_t)ptr;
	n1 = write(1, "0x", 2);
	n1 += ft_hexa(nbr);
	return (n1);
}
