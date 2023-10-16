/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:55:45 by mfornah           #+#    #+#             */
/*   Updated: 2022/10/19 12:41:59 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It returns the number of digits in the number passed to it
 * 
 * @param nb the number to be converted
 * 
 * @return The length of the number.
 */
static size_t	ft_len(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

/**
 * It takes an integer and returns a string
 * 
 * @param n the number to be converted
 * 
 * @return A string of the number.
 */
char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	long int	i;

	len = ft_len(n);
	i = n;
	str = malloc(sizeof(char) * len + 1);
	if (!(str))
		return (0);
	if (i < 0)
	{
		str[0] = '-';
		i = -i;
	}
	if (i == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (i)
	{
		str[len] = i % 10 + '0';
		len--;
		i = i / 10;
	}
	return (str);
}
