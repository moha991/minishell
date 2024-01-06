/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:43:49 by smagniny          #+#    #+#             */
/*   Updated: 2024/01/06 19:28:28 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

static void		init_values(t_var *var)
{
	var->tokens = ft_lstnew_node();
	var->fd_in = 0;
	var->fd_out = 0;
	var->len_inputline = ft_strlen(var->inputline);
	var->exit_status = 0;
	var->quoted_string = 0;
}

static  void	get_inputline(t_var *var)
{
	char			*str;

	printf("\e[0;31m");
	str = readline("(===||[\033[90m:::::::::::::::> \e[0;36m");
	if (!str || str == NULL)
	{
		var->inputline = NULL;
		return ;
	}
	if (ft_strncmp(str, "clear\0", 6) == 0)
		clear_history();
	if (ft_strncmp(str, "exit\0", 5) == 0 || ft_strncmp(str, "exit\n", 5) == 0)
	{	
		free(str);
		ft_freeenv(&var->envp);
		exit(0);
	}
	var->inputline = ft_strdup(str);
	free(str);
	add_history(var->inputline);
}

static void printNode(t_node *node)
{
    if (node == NULL)
    {
        printf("NULL\n");
        return;
    }
	printf("\tNODE:\n");
    printf("Token: %s\n", node->token->content);

    // Print flags
    printf("Flags: ");
    t_subnode *flags = node->flags;
    while (flags != NULL)
    {
        printf("%s ", flags->content);
        flags = flags->next;
    }
    printf("\n");

    // Print params
    printf("Params: ");
    t_subnode *params = node->params;
    while (params != NULL)
    {
        printf("%s ", params->content);
        params = params->next;
    }
    printf("\n");

    // Print redir
    printf("Redir: ");
    t_subnode *redir = node->redir;
    while (redir != NULL)
    {
        printf("%s ", redir->content);
        redir = redir->next;
    }
    printf("\n");

    // Print where_redir
    printf("Where Redir: ");
    t_subnode *where_redir = node->where_redir;
    while (where_redir != NULL)
    {
        printf("%s ", where_redir->content);
        where_redir = where_redir->next;
    }
    printf("\n");

}

int	main(int argc, char **argv,const char **envp)
{
	t_var	var;

	(void)argc;
	(void)argv;
	var.envp = NULL;
	var.inputline = NULL;
	cpy_env(&var.envp, envp);
	while (42)
	{
		get_inputline(&var);
		init_values(&var);
		lexer(&var);
		ft_expansor(&var);
		printNode(var.tokens);
		//pipes recursivo.
		// handleInFileRedirection(&var);
		handleOutFileRedirection(&var);
		//expansor
		if (run_builtin(&var))
			ft_exec(&var);
		base_redir(&var);
		//pipe recursivo hasta aqui.
		//reiniciar el nodo para prox serie de commandos
		ft_lstclear_node(&var.tokens);
		free(var.tokens);
		if (var.inputline != NULL)
			free(var.inputline);
			
	}
	ft_freeenv(&var.envp);
	return (0);
}

// PIPE
// LESS <
// DLESS <<
// GREAT >
// DGREAT >>
// WORD