/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:57:42 by smagniny          #+#    #+#             */
/*   Updated: 2023/10/26 19:44:16 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

//echo "hola yo me 'llamo' ""santi"
// Por mejorar
static	int	parse_quotes(char *inputline, int *i, int *start)
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
		return (1);
	}
	else
		return (0);
	
}


static	int	gnt_startpoint(t_var **var, int start)
{
	int	i;

	i = 0;
	if ((*var)->inputline == NULL || (*var)->inputline == '\0')
		return ((*var)->len_inputline);
	while ((*var)->inputline[start] == ' ')
		start++;
	while (i < start)
		i++;
	while (!is_space_or_eof((*var)->inputline[i]))
	{
		if (isdouble_operator((*var)->inputline, i))
			return (i + 2);
		else if (isingle_operator((*var)->inputline, i))
			break ;
		else if (parse_quotes((*var)->inputline, &i, &start))
			break ;
		else
			i++;
	}
	ft_lstadd_backtok(&(*var)->tokens, ft_substr((*var)->inputline, start, i - start));
	// printf("Token result: [%s] -->   st: %d    end: %d\n\n", ft_substr((*var)->inputline, start, i - start), start, i-start);
	if (start == i)
		i++;
	return (i);
}


void	unidentified_tokens(t_var *var)
{
	int			start;
	int			i;

	i = 0;
	start = 0;
	var->len_inputline = ft_strlen(var->inputline);
	printf("Len of input: %d\n", var->len_inputline);
	while (start < var->len_inputline - 1)
		start = gnt_startpoint(&var, start);// returns the pointer of the next character token.
		// printf("Next start token begins at %d (inferior to len_inputline)\n", start);
}
