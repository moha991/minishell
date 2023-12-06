/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:47:59 by mohafnh           #+#    #+#             */
/*   Updated: 2023/12/06 17:19:47 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	run_builtin(t_var *var)
{
	if (ft_strncmp(var->tokens->token, "pwd\0", 4) == 0 || ft_strncmp(var->tokens->token, "pwd ", 4) == 0)
	{
		if (pwd(var) != 0)
			printf("Error al cambiar de directorio 4: %s\n", var->tokens->token);
	}
	else if (ft_strncmp(var->tokens->token, "env", 3) == 0)
		env(var);
	else if (ft_strncmp(var->tokens->token, "cd", 2) == 0)
		cd(var->tokens);
	else if (ft_strncmp(var->tokens->token, "export", 6) == 0)
		export(var);
	else if (ft_strncmp(var->tokens->token, "echo\0", 5) == 0 || ft_strncmp(var->tokens->token, "echo ", 5) == 0)
		starts_with_echo(var->tokens);
	else if (ft_strncmp(var->tokens->token, "unset", 5) == 0)
		unset(var);
	else
		printf("Command %s not found: %s\n", var->tokens->token,  __FILE__);
}