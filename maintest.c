/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:43:49 by smagniny          #+#    #+#             */
/*   Updated: 2023/12/01 17:41:45 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

static void		init_values(t_var *var)
{
	var->tokens = NULL;
	var->nb_tokens = 0;
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
		doublefree(var->envp);
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
	var.envp = copy_2d_array(envp);
	while (42)
	{
		get_inputline(&var);
		init_values(&var);
		lexer(&var); //identificar cada palabra
		//imprimir la lista recien creada.
		run_builtin(&var);
		t_tokens *tmp;
		tmp  = var.tokens;
		while (tmp)
		{
			ft_printf("token %d: [%s]\n", i++, tmp->token);
			tmp = tmp->next;		
		}
		//reiniciar la lista de tokens para prox commando y con ello el contador de tokens.
		ft_lstcleartok(&var.tokens);
		var.nb_tokens = 0;
		free(var.inputline);
	}
	doublefree(var.envp);
	return (0);
}
