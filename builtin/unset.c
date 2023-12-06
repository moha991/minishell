/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:28:26 by smagniny          #+#    #+#             */
/*   Updated: 2023/12/06 18:09:13 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static	void deleteNode(t_env **stack, t_env *nodeToDelete)
{
	t_env *current;

	current = *stack;
    if (*stack == NULL || nodeToDelete == NULL)
        return ;
    if (*stack == nodeToDelete)
        *stack = nodeToDelete->next;
    else
	{
        while (current->next != NULL && current->next != nodeToDelete)
            current = current->next;
        if (current->next == NULL)
            return ;

        current->next = nodeToDelete->next;
    }
    free(nodeToDelete->line_env);
    free(nodeToDelete);
}

void	unset(t_var *var)
{
    t_node 	*tokens;
	t_env		*tmp;
	
	tokens = var->tokens->next; // token despues del token:'unset' con el nombre de la var de entorno. (se supone, puede haber operador)
	while (tokens && !isdouble_operator(tokens->token, 0) && !isingle_operator(tokens->token, 0))
	{
		tmp = var->envp;
		while (tmp)//var entorno.
		{
			if (ft_strncmp(tmp->line_env, tokens->token, ft_strlen(tokens->token)) == 0)
			{
				deleteNode(&var->envp, tmp);
				break ;
			}
			tmp = tmp->next;
		}
		tokens = tokens->next;
	}
}