/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:57:42 by smagniny          #+#    #+#             */
/*   Updated: 2023/10/24 19:53:21 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/header.h"

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

static	char	*get_next_token(char *inputline, int *start)
{
	char	*word_token;
	int		i;

	i = 0;
	// printf("starting point: %d\n", *start);
	if (inputline == NULL || *inputline == '\0')
		return (NULL);
	while (inputline[*start] == ' ' || inputline[*start] == '\t' 
		|| inputline[*start] == '\n')
		*start += 1;
	while (i < *start)
		i++;
	while (inputline[i] != ' ' && inputline[i] != '\t'
		&& inputline[i] != '\n' && inputline[i] != '\0')
	{
		// printf("iteration loop: %d   |   char: %c\n", i, inputline[i]);
		if (isdouble_operator(inputline, i))
		{
			i += 2;
			break ;
		}
		if (isingle_operator(inputline, i))
			break ;
		i++;
	}
	if (*start == i)
	{
		if (inputline[i] == '\n' || inputline[i] == '\0')
			return (NULL);
		word_token = ft_substr_startend(inputline, *start, i + 1);
		*start += 1;
		return (word_token);
	}
	else
	{
		word_token = ft_substr_startend(inputline, *start, i);
		// ft_printf("string token: '%s' | start: '%d' | end: '%d'\n", word_token, *start, i);
		*start = i;
		return (word_token);
	}
	*start = i;
	return (NULL);
}


static	int	gnt_startpoint(char *inputline, int start)
{
	int             i;

	i = 0;
	if (inputline == NULL || *inputline == '\0')
		return (0);
	while (inputline[start] == ' ' || inputline[start] == '\t'
		|| inputline[start] == '\n')
		start++;
	while (i < start)
		i++;
	while (inputline[i] != ' ' && inputline[i] != '\t'
		&& inputline[i] != '\n' && inputline[i] != '\0')
	{
		if (isdouble_operator(inputline, i))
		{
			i += 2;
			break ;
		}
		if (isingle_operator(inputline, i))
			break ;
		i++;
	}
	if (start == i)
		i++;
	return (i);
}

char	**unidentified_tokens(t_var *var)
{
	char	**unidentified_tokens;
	int		nb_of_tokens;
	int		start;
	int		i;

	i = -1;
	start = 0;
	nb_of_tokens = 0;
	while (start < ft_strlen(var->inputline))
	{
		start = gnt_startpoint(var->inputline, start);
		// printf("Word_token_starting point: %d\n", start);
		nb_of_tokens++;
	}
	var->len_tokens = nb_of_tokens;
	start = 0;
	unidentified_tokens = (char **)ft_calloc(nb_of_tokens, sizeof(char *));//proteger
	while (++i < nb_of_tokens)
		unidentified_tokens[i] = get_next_token(var->inputline, &start);
	return (unidentified_tokens);
}
