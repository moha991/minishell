/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:47:59 by mohafnh           #+#    #+#             */
/*   Updated: 2023/12/11 19:01:33 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	run_builtin(t_var *var)
{
	if (var->tokens != NULL)
		return (1);
	if (ft_strncmp(var->tokens->token, "pwd\0", 4) == 0 || ft_strncmp(var->tokens->token, "pwd ", 4) == 0)
		pwd(var);
	else if (ft_strncmp(var->tokens->token, "env\0", 4) == 0)
		env(var);
	else if (ft_strncmp(var->tokens->token, "cd\0", 2) == 0 || ft_strncmp(var->tokens->token, "cd ", 3) == 0)
		cd(var->tokens);
	else if (ft_strncmp(var->tokens->token, "export", 6) == 0 || ft_strncmp(var->tokens->token, "export ", 7) == 0)
		export(var);
	else if (ft_strncmp(var->tokens->token, "echo\0", 5) == 0 || ft_strncmp(var->tokens->token, "echo ", 5) == 0)
		echo(var->tokens);
	else if (ft_strncmp(var->tokens->token, "unset\0", 6) == 0 || ft_strncmp(var->tokens->token, "unset ", 6) == 0)
		unset(var);
	else
		return (1);
	return (0);
}