/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexlong.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:45:45 by mfornah           #+#    #+#             */
/*   Updated: 2022/12/01 15:48:13 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * It takes a long unsigned integer and a string of characters, 
 and prints the hexadecimal
 * representation of the integer
 * 
 * @param nbr the number to be converted
 * @param base the base of the number to be printed
 * 
 * @return The number of characters printed.
 */
int	ft_printf_hexlong(unsigned long nbr, char *base)
{
	int	nbr_final[100];
	int	prnt[3];

	prnt[0] = 0;
	prnt[1] = 0;
	prnt[2] = 0;
	if (ft_checkbase(base))
	{
		if (nbr == 0)
			prnt[2] += ft_print_putchar('0');
		while (base[prnt[1]])
			prnt[1]++;
		while (nbr)
		{
			nbr_final[prnt[0]] = nbr % prnt[1];
			nbr = nbr / prnt[1];
			prnt[0]++;
		}
		while (--prnt[0] >= 0)
			prnt[2] += ft_print_putchar(base[nbr_final[prnt[0]]]);
	}
	return (prnt[2]);
}
