/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:42:26 by mfornah           #+#    #+#             */
/*   Updated: 2022/12/02 11:22:56 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * It checks if the base is valid
 * 
 * @param base the string containing the base characters.
 * 
 * @return the length of the string.
 */
int	ft_checkbase(char *base)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		b = i + 1;
		if (base[i] == '+' || base [i] == '-' || base[i] < 32 || base[i] > 126)
			return (0);
		while (base[b])
		{
			if (base[i] == base[b])
				return (0);
			b++;
		}
		i++;
	}
	return (1);
}
