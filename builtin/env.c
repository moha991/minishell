/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:36:16 by mohafnh           #+#    #+#             */
/*   Updated: 2023/12/01 17:21:27 by smagniny         ###   ########.fr       */
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
