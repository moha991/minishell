/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:43:49 by smagniny          #+#    #+#             */
/*   Updated: 2023/10/25 13:39:35 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

static  char    *get_inputline(t_var *var)
{
	char			*str;

	(void)var;
	ft_printf("$> ");
	str = readline(NULL);
	if (ft_strncmp(str, "clear", 5) == 0)
	{
		free(str);
		clear_history();
	}
	if (ft_strncmp(str, "exit", 4) == 0)
		exit(0);
    add_history(str);
	return (str);
}

int	main(int argc, char **argv, char **envp)
{
	t_var	var;
	int		i;

	(void)argc;
	(void)argv;
	var.envp = envp;
	var.len_tokens = 0;
	while (1)
	{
		i = -1;
		var.inputline = get_inputline(&var);
		var.u_tokens = unidentified_tokens(&var); //identificar cada palabra
		while (++i < var.len_tokens)
			printf("token: %s\n", var.u_tokens[i]);
		//doublefree(var.u_tokens); !!!!!!!!!!!
		//struct_parser();
		//executor_of_the_tree_createdby_struct_parser();
	}
	return (0);
}
