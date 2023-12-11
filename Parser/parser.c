/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:29:01 by smagniny          #+#    #+#             */
/*   Updated: 2023/12/06 18:09:24 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	parser(t_var *var)
{
	t_node	*tmp;

	tmp = var->tokens;
	while (var->tokens)
	{
		if (ft_strncmp(var->tokens->token, "-", 1) == 0)
			var->tokens->flags = var->
	}
}