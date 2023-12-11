/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:57:42 by smagniny          #+#    #+#             */
/*   Updated: 2023/12/11 16:21:06 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static	char	*check_word_rec(t_var *var, int *start, int *i, char *token_string)
{
	char	*upd_token_string;

	if (isdoublequote(var->inputline[*i]))// si te encuentras una comilla.
	{
		if (isdoublequote(var->inputline[++(*i)]))
		{
			(*i)++;
			(*start) += 2;
			return (token_string);
		}
		else
		{
			(*start)++;
			upd_token_string = ft_strjoinfreee(token_string, get_str_doublequoted(var,i, start)); //recuperar la string entre comillas dobles. y pone el iterador en la posicion siguiente
		}
	}
	else if (issinglequote(var->inputline[*i]))
	{
		if (issinglequote(var->inputline[++(*i)]))
		{
			(*i)++;
			(*start) += 2;
			return (token_string);
		}
		else
		{
			(*start)++;
			upd_token_string = ft_strjoinfreee(token_string, get_str_singlequoted(var, i, start)); //recuperar la string entre comillas simples.
			*start = *i;
		}
	}
	else
		upd_token_string = ft_strjoinfreee(token_string, get_word(var,i, start));
	return (upd_token_string);
}

static	int detect_flag(t_var *var, char *token_string)
{
	int			i;

	i = 1;
	if (ft_strncmp(token_string, "-", 1) == 0)
	{
		if (ft_strncmp(var->tokens->token, "echo", 4) == 0 && var->tokens->redir == NULL && var->tokens->where_redir == NULL)
		{
			while (token_string[i] == 'n')
				i++;
			if (token_string[i] == '\0' && var->tokens->params == NULL)
				ft_lstadd_back_subnode(&var->tokens->flags, ft_lstnew_subnode(token_string));
			else
				ft_lstadd_back_subnode(&var->tokens->params, ft_lstnew_subnode(token_string));
		}
		else
			ft_lstadd_back_subnode(&var->tokens->flags, ft_lstnew_subnode(token_string));
		return (0);
	}
	return (1);
}

static  int gnt_startpoint(t_var *var, int start)
{
    int         i;
	char		*token_string;
	int			word;

    i = 0;
	word = 0;
	token_string = NULL;
    if ((var->inputline == NULL)
        && start < var->len_inputline)
        return (var->len_inputline);
    while (var->inputline[start] == ' ' || var->inputline[start] == '\t')
        start++;
    i = start;
    while (i < var->len_inputline && !is_space_or_eof(var->inputline[i]))//until a space or EOF
    {
        if (isdouble_operator(var->inputline, i))// tokenize >> <<
        {
			if (word)
				break ;
			if (var->tokens == NULL)
				ft_lstadd_back_node(&var->tokens, ft_lstnew_node(NULL));
            i += 2;
			token_string = ft_substr(var->inputline, start, i - start);
			start = i;
			ft_lstadd_back_subnode(&var->tokens->redir, ft_lstnew_subnode(token_string));
			while (var->inputline[start] == ' ' || var->inputline[start] == '\t')
        		start++;
    		i = start;
			token_string = 0;
			token_string = check_word_rec(var, &start, &i, NULL);
			ft_lstadd_back_subnode(&var->tokens->where_redir, ft_lstnew_subnode(token_string));
			// checkear disponibilidad archivo en caso de input
			token_string = NULL;
        }
        else if (isingle_operator(var->inputline, i))// tokenize > < 
        {
			if (word)
				break;
			if (var->tokens == NULL)
				ft_lstadd_back_node(&var->tokens, ft_lstnew_node(NULL));
            i++;
			token_string = ft_substr(var->inputline, start, i - start);
			start = i;
			ft_lstadd_back_subnode(&var->tokens->redir, ft_lstnew_subnode(token_string));
			while (var->inputline[start] == ' ' || var->inputline[start] == '\t')
        		start++;
    		i = start;
			token_string = NULL;
			token_string = check_word_rec(var, &start, &i, NULL);
			ft_lstadd_back_subnode(&var->tokens->where_redir, ft_lstnew_subnode(token_string));
			token_string = NULL;
        }
		else
        {
			token_string = check_word_rec(var, &start, &i, token_string);
			word = 1;
        }
    }
    if (token_string != NULL && *token_string != '\0' && *token_string != '|')
    {
		word = 0;
		if (detect_flag(var, token_string))
		{
			if (var->tokens->token == NULL)
			{
				// printf("ADDING NODE w token: [%s] w index=%d\n", token_string, i);
				var->tokens->token = token_string;
        		// ft_lstadd_back_node(&var->tokens, ft_lstnew_node(token_string));
			}
			else
			{
				// printf("Se ha actualizado el nodo con nuevos params.\nNODE:\n\ttoken: %s\n", var->tokens->token);
				// printf("\tParams: [%s] w index=%d\n", token_string, i);
        		ft_lstadd_back_subnode(&var->tokens->params, ft_lstnew_subnode(token_string));
			}
		}
	}
    return (i);
}

void	lexer(t_var *var)
{
	int			start;

	start = 0;
	while (start < var->len_inputline)
		start = gnt_startpoint(var, start); // returns the index of the next character (NODE !) token.-
}
