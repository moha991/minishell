/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:57:11 by mfornah           #+#    #+#             */
/*   Updated: 2022/10/19 12:41:30 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Ft_memset() takes a pointer to a memory area, a character to fill it with,
 *  and a size, and fills the
 * memory area with the character
 * 
 * @param dest This is the pointer to the memory area to be filled.
 * @param ch the character to fill the memory with
 * @param n the number of bytes to be set to the value ch
 * 
 * @return The address of the first byte of the memory area dest.
 */
void	*ft_memset(void *dest, int ch, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ch;
		i++;
	}
	return (dest);
}
