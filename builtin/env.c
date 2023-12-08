/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:36:16 by mohafnh           #+#    #+#             */
/*   Updated: 2023/12/08 14:03:52 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	env(t_var *var)
{
	t_env *tmp;

	if (var->tokens->flags != NULL)
	{	
		printf("Minishell: env: no options can be handled.\n");
		return (1);
	}
	tmp = var->envp;
	if (var->tokens->token != NULL)
	{
		while (tmp)
		{
			ft_putendl_fd(tmp->line_env, 1);
			ft_putchar_fd('\n', 1);
			tmp = tmp->next;
		}
	}
	return (0);
}
