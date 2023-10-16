/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:22:45 by mfornah           #+#    #+#             */
/*   Updated: 2022/10/19 12:14:46 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * If the destination is less than the source, then copy 
 * the source to the destination from the end of
 * the source to the beginning of the source. Otherwise, 
 * copy the source to the destination from the
 * beginning of the source to the end of the source
 * 
 * 
 * @param dst This is the destination array where the content is to be copied,
 *  type-casted to a
 * pointer.
 * @param src The source string.
 * @param len the number of bytes to copy
 * 
 * @return A pointer to the destination string.
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	if ((size_t)dst - (size_t)src < len)
	{
		i = len - 1;
		while (i >= 0 && i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
