/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:34:27 by mohafnh           #+#    #+#             */
/*   Updated: 2023/12/06 18:09:04 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int cd(t_node *tokens)
{
	char	*where;
	int		value;
	
	tokens =  tokens->next;
	value = 0;
	if (!tokens)
	{
		where = getenv("HOME");
		if(!where)
			return(printf("cd: HOME not set\n"));
	}
	else
		where = ft_strdup(tokens->token);
	if (!where)
		return (perror("Error in minishell"), 1);
	if (ft_strncmp(where, "", 1) != 0)
	{
		value = chdir(where);
		if (value == -1)
			return (printf("Change no posible"));
	}
	else
		free(where);
	return (0);
	
}
