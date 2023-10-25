/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:17:19 by smagniny          #+#    #+#             */
/*   Updated: 2023/10/25 12:29:07 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	isingle_operator(char *line, int i)
{
	return (line[i] == '|' || (line[i] == '>' && line[(i + 1)] != '>')
		|| (line[i] == '<' && line[(i + 1)] != '<'));
}

int	isdouble_operator(char *line, int i)
{
	return ((line[i] == '>' && line[(i + 1)] == '>')
		|| (line[i] == '<' && line[(i + 1)] == '<'));
}

char	*ft_copytoken(char *inputline, int *start, int *end)
{
	char	*newtoken;

	if (*start == *end)
	{
		if (inputline[*end] == '\n' || inputline[*end] == '\0')
			return (NULL);
		newtoken = ft_substr_startend(inputline, *start, (*end) + 1);
		*start += 1;
		return (newtoken);
	}
	else
	{
		newtoken = ft_substr_startend(inputline, *start, *end);
		*start = *end;
		return (newtoken);
	}
}

