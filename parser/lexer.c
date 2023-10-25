/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:57:42 by smagniny          #+#    #+#             */
/*   Updated: 2023/10/25 12:30:12 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static	char	*get_next_token(char *inputline, int *start)
{
	char	*word_token;
	int		i;

	i = 0;
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
		if (isdouble_operator(inputline, i))
		{
			i += 2;
			break ;
		}
		if (isingle_operator(inputline, i))
			break ;
		i++;
	}
	word_token = ft_copytoken(inputline, start, &i);
	return (word_token);
}


static	int	gnt_startpoint(char *inputline, int start)
{
	int	i;

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
		nb_of_tokens++;
	}
	var->len_tokens = nb_of_tokens;
	start = 0;
	unidentified_tokens = (char **)ft_calloc(nb_of_tokens, sizeof(char *));
	if (!unidentified_tokens)
		return (NULL);
	while (++i < nb_of_tokens)
		unidentified_tokens[i] = get_next_token(var->inputline, &start);
	return (unidentified_tokens);
}
