/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:47:59 by mohafnh           #+#    #+#             */
/*   Updated: 2023/12/02 17:33:15 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	run_builtin(t_var *var)
{
	char	*path;
	int		pwd_result;

	if (ft_strncmp(var->tokens->token, "pwd", 3) == 0)
	{
		path = var->tokens->token + 3;
		pwd_result = pwd(path);
		if (pwd_result != 0)
			printf("Error al cambiar de directorio 4: %d\n", pwd_result);
	}
	else if (ft_strncmp(var->tokens->token, "env", 3) == 0)
		env(var);
	else if (ft_strncmp(var->tokens->token, "cd", 2) == 0)
		cd(var->tokens);
	else if (ft_strncmp(var->tokens->token, "export", 6) == 0)
		export(var);
	else if (ft_strncmp(var->tokens->token, "echo", 4) == 0)
		starts_with_echo(var->tokens);
	else if (ft_strncmp(var->tokens->token, "unset", 5) == 0)
		unset(var);
	else
		printf("Command '%s' not found: %s\n", var->tokens->token,  __FILE__);
}