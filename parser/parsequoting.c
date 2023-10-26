/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsequoting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:54:42 by smagniny          #+#    #+#             */
/*   Updated: 2023/10/26 19:49:26 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"


int	parse_quotes(char *inputline, int *i, int *start)
{
	if (inputline[*i] == SINGLEQ)
	{
		printf("SINGLEQ FOUND at position %d from start %d;\n", *i, *start);
		while (!issinglequote(inputline[++(*i)]));
		(*start)++;
		printf("	|----> SINGLEQ FOUND at position %d from start %d  ; tkres=[%s]\n\n", *i, *start, ft_substr(inputline, *start,  (*i) - (*start)));
		return (1);
	}
	else if (inputline[*i] == DOUBLEQ)
	{
		printf("DOUBLEQ FOUND at position %d from start %d\n", *i, *start);
		while (!isdoublequote(inputline[++(*i)]));
		(*start)++;
		if (*start == *i)
		{	
			printf("	|----> DOUBLEQ FOUND at position %d from start %d  ; tkres=[%s]  ---> EMPTY SKIPPING\n\n", *i, *start, ft_substr(inputline, *start , (*i) - (*start)));
			while (!isdoublequote(inputline[++(*i)]));
		}
		printf("	|----> DOUBLEQ FOUND at position %d from start %d  ; tkres=[%s]\n\n", *i, *start, ft_substr(inputline, *start , (*i) - (*start)));
		(*i)++;
		return (1);
	}
	else
		return (0);
	
}
//echo "hola yo me 'llamo' ""santi"
// Por mejorar