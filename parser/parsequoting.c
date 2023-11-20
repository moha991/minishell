/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsequoting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:54:42 by smagniny          #+#    #+#             */
/*   Updated: 2023/11/20 22:19:56 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

char	*ft_strjoinfreee(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;

	if (!s2 && !s1)
		return (0);
	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_str)
		return (0);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (new_str);
}

char	*get_word(t_var *var, int *i, int *start)
{
	char *str;

	str = NULL;
	// printf("get_word starting at letter %c w i:%d\n", var->inputline[*start], *i);
	if (*i >= var->len_inputline)
		return (NULL);
	while (ft_isascii(var->inputline[*i]) && (!isdoublequote(var->inputline[*i]) && !issinglequote(var->inputline[*i]) && !is_space_or_eof(var->inputline[*i]) 
		&& !isingle_operator(var->inputline, *i) && !isdouble_operator(var->inputline, *i) && var->inputline[*i] != '='))
		(*i)++;
	if (*start < *i)
		str = ft_substr(var->inputline, *start, *i - *start);
	*start = *i;
	return (str);
}

char	*get_str_doublequoted(t_var *var, int *i, int *start)
{
	char	*token_string;

	token_string = NULL;
	// printf("getZ_str_singlequote: OK\n");
	//!!!! ASUMIENDO QUE START=I; es decir que no hay letras antes de una comilla, tiene que haber un separador, ej; a 'a'a ( start)
	// printf("Entering DOUBLE w: st: %d  - i: %d\n", *start, *i);
	while ((*i) < var->len_inputline && ft_isascii(var->inputline[*i]) && !isdoublequote(var->inputline[*i]))
		(*i)++;
	if (*start != *i && *start < *i)
		token_string = ft_substr(var->inputline, *start, (*i - *start));
	// printf("final result indexes --> start: %d     i: %d\n", *start, *i);
	*start = ++(*i);
	// printf("final result Word ---> [%s] &i: %d st:%d\n", token_string, *i, *start);
	return (token_string);
}


char	*get_str_singlequoted(t_var *var, int *i, int *start)
{
	char	*token_string;
	token_string = NULL ;

	 //!!!! ASUMIENDO QUE START=I; es decir que no hay letras antes de una comilla, tiene que haber un separador, ej; a 'a'a ( start)
	// printf("Entering SINGLE w: st: %d  - i: %d\n", *start, *i);
	while ((*i) < var->len_inputline && ft_isascii(var->inputline[*i]) && !issinglequote(var->inputline[*i]))
		(*i)++;
	if (*start != *i && *start < *i)
		token_string = ft_substr(var->inputline, *start, (*i - *start));
	if (*token_string)
	{
		// printf("final result indexes --> start: %d     i: %d\n", *start, *i);
		*start = ++(*i);
		// printf("final result Word ---> [%s]\n", token_string);
		return (token_string);
	}
	else
	{
		++(*i);
		free(token_string);
		return (0);
	}
}

