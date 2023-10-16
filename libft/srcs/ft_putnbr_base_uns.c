/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_uns.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:26:14 by mfornah           #+#    #+#             */
/*   Updated: 2022/12/01 15:52:22 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_uns(unsigned int nbr, char *base)
{
	int	nbr_final[100];
	int	i;
	int	prnthex;

	i = 0;
	prnthex = 0;
	if (nbr == 0)
		prnthex += ft_print_putchar('0');
	while (nbr)
	{
		nbr_final[i] = nbr % 16;
		nbr = nbr / 16;
		i++;
	}
	while (--i >= 0)
		prnthex += ft_print_putchar(base[nbr_final[i]]);
	return (prnthex);
}
