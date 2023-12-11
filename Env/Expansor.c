/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:52:04 by smagniny          #+#    #+#             */
/*   Updated: 2023/12/09 18:04:25 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static  char    *expand(t_env *env, char *dollar_str)
{
    
}

void    ft_expansor(t_var *var)
{
    t_subnode *tmp;

    if (ft_strrchr(var->tokens->token, '$'))
        var->tokens->token = expand(var->envp, ft_strrchr(var->tokens->token, '$'));
    while (tmp)
}