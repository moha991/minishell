/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohafnh <mohafnh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:53:19 by mfornah           #+#    #+#             */
/*   Updated: 2023/10/15 12:39:03 by mohafnh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It counts the number of words in a string
 * 
 * @param s The string to be split.
 * @param c the delimiter
 * 
 * @return The number of words in the string.
 */
static int	get_nwords(char const *s, char c)
{
	int	nwords;

	nwords = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s == c)
		{
			nwords++;
			while (*s == c)
				s++;
		}
		else
			s++;
	}
	nwords++;
	return (nwords);
}

/**
 * This function frees the memory allocated to the 2D array of strings.
 * 
 * @param memry This is the pointer to the array of pointers.
 * @param aux This is the number of lines in the file.
 * 
 * @return A pointer to the memory address of the first element of the array.
 */
static void	*freemmory(char **memry, size_t aux)
{
	size_t	i;

	i = 0;
	while (i < aux)
	{
		free(memry[i]);
		i++;
	}
	free(memry);
	return (NULL);
}

/**
 * It takes a string, a character, and a number of words, 
 * and it splits the string into an array of
 * strings, using the character as a delimiter
 * 
 * @param ptr is the pointer to the array of strings.
 * @param str The string to be split.
 * @param c the delimiter
 * @param nwords number of words in the string
 * 
 * @return A pointer to a pointer to a char.
 */
static void	save_words(char **ptr, char *str, char c, int nwords)
{
	int		i;
	char	*aux;

	i = 0;
	if ((nwords > 0) && *str)
	{
		while (i < (nwords - 1))
		{
			aux = ft_strchr(str, c);
			ptr[i++] = ft_substr(str, 0, aux - str);
			if (ptr == 0)
			{
				freemmory(ptr, i);
				return ;
			}
			while (*aux == c)
				aux++;
			str = aux;
		}
		ptr[i++] = ft_strdup(str);
		ptr[i] = 0;
	}
}

/**
 * Split the string s into words separated by the character c,
 *  and return a pointer to an array of
 * pointers to the words
 * 
 * @param s The string to be split.
 * @param c the character to split the string by
 * 
 * @return A pointer to an array of pointers to characters.
 */

char	**ft_split(char  *s, char c)
{
	int		nwords;
	char	**ptr;
	char	*str;
	char	a[2];

	a[0] = c;
	a[1] = '\0';
	if (s)
	{
		str = ft_strtrim(s, a);
		if (str)
		{
			nwords = get_nwords(str, c);
			ptr = ft_calloc((nwords + 1), sizeof(char *));
			if (ptr)
				save_words(ptr, str, c, nwords);
			free(str);
			return (ptr);
		}
	}
	return (0);
}
