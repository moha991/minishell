/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 08:44:19 by mfornah           #+#    #+#             */
/*   Updated: 2022/10/19 12:41:23 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The function ft_memchr() locates the first occurrence 
 * of c (converted to an unsigned char) in string
 * s
 * 
 * @param s The memory area to be searched.
 * @param c The character to search for.
 * @param n The number of bytes to be searched.
 * 
 * @return A pointer to the first occurence of the character c in the string s.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((((unsigned char *)s1)[i] != ((unsigned char *)s2)[i]))
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return ('\0');
}
