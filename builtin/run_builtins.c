/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohafnh <mohafnh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:47:59 by mohafnh           #+#    #+#             */
/*   Updated: 2023/11/20 20:37:46 by mohafnh          ###   ########.fr       */
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
	if (ft_strncmp(var->tokens->token, "env", 3) == 0)
		env(var);
	if (ft_strncmp(var->tokens->token, "cd", 2) == 0)
		cd(var->tokens);
	/* if (ft_strncmp(var->tokens->token, "export", 2) == 0)
		export(var); */
	if (ft_strncmp(var->tokens->token, "echo", 4) == 0)
		starts_with_echo(var->tokens);
	
}