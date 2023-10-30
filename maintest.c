/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:43:49 by smagniny          #+#    #+#             */
/*   Updated: 2023/10/30 20:07:13 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

static void		init_values(t_var *var)
{
	var->tokens = NULL;
	var->nb_tokens = 0;
	var->len_inputline = 0;
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
		exit(0);
	var->inputline = ft_strdup(str);
	add_history(var->inputline);
}

int	main(int argc, char **argv, char **envp)
{
	t_var	var;
	int		i;

	(void)argc;
	(void)argv;
	var.envp = envp;
	while (1)
	{
		i = -1;
		get_inputline(&var);
		init_values(&var);
		unidentified_tokens(&var); //identificar cada palabra
	
		//imprimir la lista recien creada.
		t_tokens *tmp;
		tmp  = var.tokens;
		while (tmp)
		{
			ft_printf("token %d: [%s]\n", ++i, tmp->token);
			tmp = tmp->next;
			var.nb_tokens++;
		}
		printf("number of tokens; %d\n", var.nb_tokens);
		//reiniciar la lista de tokens para prox commando y con ello el contador de tokens.
		ft_lstcleartok(&var.tokens);
		var.nb_tokens = 0;
	}
	free(var.inputline);
	return (0);
}
