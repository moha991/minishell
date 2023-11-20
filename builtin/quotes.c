/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:40:16 by mohafnh           #+#    #+#             */
/*   Updated: 2023/11/02 17:22:45 by mfornah          ###   ########.fr       */
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
		printf("|----> SINGLEQ FOUND at position%dfrom start %d;\n\n",*i,*start);
		return (1);
	}
	else if (inputline[*i] == DOUBLEQ)
	{
		printf("DOUBLEQ FOUND at position %d from start %d\n", *i, *start);
        while (!isdoublequote(inputline[++(*i)]));
		(*start)++;
		if (*start == *i)
		{
            printf("->DOUBLEQ FOUND at position%dfrom start%d;EMPTY SKIPPING\n\n",*i,*start);
            while   (!isdoublequote(inputline[++(*i)]));
		}
		printf("|---->DOUBLEQ FOUND at position%dfrom start %d;\n\n",*i, *start);
		(*i)++;
		return (1);
	}
	else
		return (0);
}
