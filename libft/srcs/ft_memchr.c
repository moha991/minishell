/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 07:46:34 by mfornah           #+#    #+#             */
/*   Updated: 2022/10/19 12:42:01 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The function ft_memchr() locates the first occurrence 
 *of c (converted to an unsigned char) in string
 * s
 * 
 * @param s The memory area to be searched.
 * @param c The character to search for.
 * @param n The number of bytes to be searched.
 * 
 * @return A pointer to the first occurence of the character c in the string s.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *) s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
