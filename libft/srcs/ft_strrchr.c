/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohafnh <mohafnh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 07:14:26 by mfornah           #+#    #+#             */
/*   Updated: 2023/10/15 12:33:37 by mohafnh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * It returns a pointer to the last occurrence of 
 * the character c in the string str.
 * @param str This is the string to be searched.
 * @param c The character to search for.
 * @return The address of the last occurrence of 
 * the character c in the string str.
 */
char	*ft_strrchr(char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
			i--;
	}
	return (0);
}
