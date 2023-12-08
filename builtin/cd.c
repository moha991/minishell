/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:34:27 by mohafnh           #+#    #+#             */
/*   Updated: 2023/12/08 14:03:45 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int cd(t_node *tokens)
{
	char	*where;
	int		value;

	value = 0;
	if (tokens->flags != NULL)
	{	
		printf("Minishell: cd: no options can be handled.\n");
		return (1);
	}
	if (!tokens)
	{
		where = getenv("HOME");
		if(!where)
			return(printf("cd: $HOME not set\n"));
	}
	else
		where = ft_strdup(tokens->params->content);
	if (ft_strncmp(where, "", 1) != 0)
	{
		value = chdir(where);
		if (value == -1)
			return (printf("cd: Invalid path\n"));
		free(where);
	}
	else
		free(where);
	return (0);
	
}
