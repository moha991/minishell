/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohafnh <mohafnh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:47:45 by mfornah           #+#    #+#             */
/*   Updated: 2023/10/21 18:35:32 by mohafnh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The function ft_strchr() locates the first 
 * occurrence of c (converted to a char) in the string
 * pointed to by s
 * 
 * @param str This is the string to be searched.
 * @param c The character to search for.
 * 
 * @return A pointer to the first occurrence of 
 * the character c in the string str.
 */
char	*ft_strchr( char *str, int c)
{
	while (*str)
	{
		if (*str == (const char)c)
			return ((char *) str);
			str++;
	}	
	if (*str == (const char)c)
	{
		return ((char *) str);
	}
	return (0);
}
