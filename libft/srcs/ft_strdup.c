/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohafnh <mohafnh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:50:23 by mfornah           #+#    #+#             */
/*   Updated: 2023/10/15 12:34:04 by mohafnh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * It copies the string pointed to by src, 
 * including the terminating null byte ('\0'), to a buffer
 * pointed to by dst.
 * 
 * @param src The string to be copied.
 * 
 * @return A pointer to a new string which is a 
 * duplicate of the string pointed to by src.
 */
char	*ft_strdup(char *src)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dst)
		return (NULL);
	while (src[i] != '\0')
	{
		dst[i] = src [i];
		i++;
	}
	dst [i] = '\0';
	return (dst);
}
