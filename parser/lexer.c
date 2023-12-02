/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:57:42 by smagniny          #+#    #+#             */
/*   Updated: 2023/12/02 18:12:16 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static	char	*check_word_rec(t_var *var, int *start, int *i, char *token_string)
{
	char	*upd_token_string;

	//printf("check_word enter withs: %s && pos:[%c] && st: %d && len: %d\n", token_string, var->inputline[*start], *start, var->len_inputline);
	if (isdoublequote(var->inputline[*i]))// si te encuentras una comilla.
	{
		if (isdoublequote(var->inputline[++(*i)]))
		{
			(*i)++;
			(*start) += 2;
			//printf("loop shift empty double quote at final pos %d && %d\n", (*start), *i);
			return (token_string);
		}
		else
		{
			(*start)++;
			upd_token_string = ft_strjoinfreee(token_string, get_str_doublequoted(var,i, start)); //recuperar la string entre comillas dobles. y pone el iterador en la posicion siguiente
		}
		//printf("Ultima letra por ver: %c", var->inputline[*i]);
	}
	else if (issinglequote(var->inputline[*i]))
	{
		if (issinglequote(var->inputline[++(*i)]))
		{
			(*i)++;
			(*start) += 2;
			//printf("loop shift empty single quote at final pos %d:[%c]\n", (*start), var->inputline[*i]);
			return (token_string);
		}
		else
		{
			(*start)++;
			upd_token_string = ft_strjoinfreee(token_string, get_str_singlequoted(var, i, start)); //recuperar la string entre comillas dobles.
			*start = *i;
		}
	}
	else
		upd_token_string = ft_strjoinfreee(token_string, get_word(var,i, start));
	return (upd_token_string);
}

static  int gnt_startpoint(t_var *var, int start)
{
    int         i;
	char		*token_string;
	int			word;

    i = 0;
	word = 0;
	token_string = NULL;
	//primera verificacion anti-null || \0
    if ((var->inputline == NULL || *var->inputline == '\0')
        && start < var->len_inputline)
        return (var->len_inputline);
	//saltarse espacios e igualar iterador end (=i) si hace falta
    while (var->inputline[start] == ' ' || var->inputline[start] == '\t')
        start++;
    i = start;
    while (i < var->len_inputline && !is_space_or_eof(var->inputline[i]))//until a space or EOF
    {
        if (isdouble_operator(var->inputline, i))// tokenize >> <<
        {
			if (word)
				break ;
            i += 2;
			token_string = ft_substr(var->inputline, start, i - start);
			// printf("token double operator: [%s]\n", token_string);
			start = i;
			break ;
        }
        else if (isingle_operator(var->inputline, i))// tokenize > <
        {
			if (word)
				break;
            i++;
			token_string = ft_substr(var->inputline, start, i - start);
			// printf("token single operator: [%s]\n", token_string);
			start = i;
			break ;
        }
		else if (var->inputline[i] == '=' && var->inputline[i - 1] != ' ') // tokenize = sign
        {
			if (word)
				break ;
			start = i++;
			token_string = ft_substr(var->inputline, start, i - start);
			// printf("ADDING TO LIST: equal sign [%s] w index=%d\n", token_string, i);
			start = i;
			break ;
        }
		else
        {
			token_string = check_word_rec(var, &start, &i, token_string);
			word = 1;
        }
    }
    if (token_string != NULL && *token_string != '\0')
    {
		word = 0;
		// printf("ADDING TO LIST final: [%s] w index=%d\n", token_string, i);
        ft_lstadd_backtok(&var->tokens, ft_lstnewtok(token_string));
	}
    // printf("Token result: [%s] -->   st: %d    end: %d\n\n", ft_substr(var->inputline, start, i - start), start, i-start);
    return (i);
}

void	lexer(t_var *var)
{
	int			start;

	start = 0;
	while (start < var->len_inputline)
		start = gnt_startpoint(var, start); // returns the index of the next character token.-
		//printf("start loop: %d\n", start);
}
