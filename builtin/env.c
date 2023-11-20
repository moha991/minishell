/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohafnh <mohafnh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:36:16 by mohafnh           #+#    #+#             */
/*   Updated: 2023/11/19 21:50:49 by mohafnh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	env(t_var *var)
{
	int	i;
	int	len;

	i = -1;
	len = ft_lendb(var->envp);
	if (var->tokens->token != NULL)
	{
		while (++i < len)
		{
			ft_putendl_fd(var->envp[i], 1);
			ft_putchar_fd('\n', 1);
		}
	}
	return (0);
}
