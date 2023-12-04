/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:43:49 by smagniny          #+#    #+#             */
/*   Updated: 2023/12/04 17:36:47 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

static void		init_values(t_var *var)
{
	var->tokens = NULL;
	var->len_inputline = ft_strlen(var->inputline);
}

static  void	get_inputline(t_var *var)
{
	char			*str;

	printf("\e[0;31m");
	str = readline("\n(===||[\033[90m:::::::::::::::> \e[0;36m");
	if (ft_strncmp(str, "clear", 5) == 0)
	{
		free(str);
		clear_history();
	}
	if (ft_strncmp(str, "exit", 4) == 0)
	{	
		ft_freeenv(&var->envp);
		exit(0);
	}
	var->inputline = ft_strdup(str);
	free(str);
	add_history(var->inputline);
}

int	main(int argc, char **argv,const char **envp)
{
	t_var	var;
	int		i;

	i = 0;
	(void)argc;
	(void)argv;
	var.envp = NULL;
	cpy_env(&var.envp, envp);
	while (42)
	{
		get_inputline(&var);
		init_values(&var);
		lexer(&var);

		
		run_builtin(&var);
		//reiniciar la lista de tokens para prox serie de commandos
		ft_lstcleartok(&var.tokens);
		free(var.inputline);
	}
	ft_freeenv(&var.envp);
	return (0);
}
