/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:52:04 by smagniny          #+#    #+#             */
/*   Updated: 2023/12/11 18:44:34 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static  char    *expand(t_env *env, char *dollar_str)
{
    t_env   *tmp;
    char    *str;

    tmp = env;
    while (tmp)
    {
        if (ft_strncmp(tmp->line_env, dollar_str + 1, ft_strlen(dollar_str) - 1) == 0)
        {
            str = ft_strdup(tmp->line_env + ft_strlen(dollar_str));
            free(dollar_str);
            return (str);
        }
        tmp = tmp->next;
    }
    //printear mensaje de error con que no ha encontrado la variable en las var de entorno
    return (NULL);
}

static void expansor_sublist(t_subnode   *sublist_ptr, t_var *var)
{   
    t_subnode   *tmp;

    tmp = sublist_ptr;
    while (tmp)
    {
        if (tmp->content && ft_strrchr(tmp->content, '$'))
        {
            tmp->content = expand(var->envp, ft_strrchr(tmp->content, '$'));
        }
        tmp = tmp->next;
    }
}

void    ft_expansor(t_var *var)
{
    if (var->tokens == NULL)
        return ;
    if (ft_strrchr(var->tokens->token, '$'))
        var->tokens->token = expand(var->envp, ft_strrchr(var->tokens->token, '$'));
    expansor_sublist(var->tokens->flags, var);
    expansor_sublist(var->tokens->params, var);
    expansor_sublist(var->tokens->redir, var);
    expansor_sublist(var->tokens->where_redir, var);
}