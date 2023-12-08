/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:47:59 by mohafnh           #+#    #+#             */
/*   Updated: 2023/12/08 14:39:11 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	run_builtin(t_var *var)
{
	if (ft_strncmp(var->tokens->token, "pwd\0", 4) == 0 || ft_strncmp(var->tokens->token, "pwd ", 4) == 0)
		pwd(var);
	else if (ft_strncmp(var->tokens->token, "env\0", 4) == 0)
		env(var);
	else if (ft_strncmp(var->tokens->token, "cd\0", 2) == 0 || ft_strncmp(var->tokens->token, "cd ", 3) == 0)
		cd(var->tokens);
	else if (ft_strncmp(var->tokens->token, "export\0", 6) == 0 || ft_strncmp(var->tokens->token, "export ", 6) == 0)
		export(var);
	else if (ft_strncmp(var->tokens->token, "echo\0", 5) == 0 || ft_strncmp(var->tokens->token, "echo ", 5) == 0)
		echo(var->tokens);
	else if (ft_strncmp(var->tokens->token, "unset\0", 6) == 0 || ft_strncmp(var->tokens->token, "unset ", 6) == 0)
		unset(var);
	else
		printf("Command %s not found: %s\n", var->tokens->token,  __FILE__);
}