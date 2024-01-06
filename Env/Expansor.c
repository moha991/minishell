/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:52:04 by smagniny          #+#    #+#             */
/*   Updated: 2024/01/06 18:42:51 by smagniny         ###   ########.fr       */
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
            return (str);
        }
        tmp = tmp->next;
    }
    //printear mensaje de error con que no ha encontrado la variable en las var de entorno
    return (NULL);
}

// static void expansor_sublist(t_subnode   *sublist_ptr, t_var *var)
// {   
//     t_subnode   *tmp;
//     char        *res;

//     res = NULL;
//     tmp = sublist_ptr;
//     while (tmp)
//     {
//         res = ft_strrchr(tmp->content, '$');
//         if (tmp->quoted_string == 0 && tmp->content && res && ft_strlen(res) > 1)
//         {
//             if (res[1] == '?' && res[2] == '\0')
//                 tmp->content = ft_itoa(var->exit_status);
//             else
//                 tmp->content = expand(var->envp, ft_strrchr(tmp->content, '$'));
//         }
//         tmp = tmp->next;
//     }
// }

static  int count_letter_bf_expansion(char *string)
{
    int  i;
    
    if (string == NULL)
        return (0);
    i = 0;
    while (string[i] != '$' && string[i])
        i++;
    return (i);
}

static void expansor_sublist(t_subnode   *sublist_ptr, t_var *var)
{   
    t_subnode   *tmp;
    char        *str;
    // char        *expanded;
    char        *res;
    int         k;

    tmp = sublist_ptr;
    str = NULL;
    while (tmp)
    {
        k = count_letter_bf_expansion(tmp->content);
        if (k)
            str = ft_substr(tmp->content, 0, k);
        res = ft_strrchr(tmp->content, '$');
        if (tmp->quoted_string == 0 && tmp->content && res && ft_strlen(res) > 1)
        {
            if (res[1] == '?' && res[2] == '\0')
                res = ft_itoa(var->exit_status);
            else
                res = expand(var->envp, ft_strrchr(tmp->content, '$'));
            tmp->content = ft_strjoinfreee(str, res);
        }
        tmp = tmp->next;
    }
}

void    ft_expansor(t_var *var)
{
    if (var->tokens == NULL || var->tokens->token == NULL)
        return ;
    expansor_sublist(var->tokens->token, var);
    expansor_sublist(var->tokens->flags, var);
    expansor_sublist(var->tokens->params, var);
    expansor_sublist(var->tokens->redir, var);
    expansor_sublist(var->tokens->where_redir, var);
}