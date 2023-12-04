/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:03:39 by smagniny          #+#    #+#             */
/*   Updated: 2023/12/04 19:19:48 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void    handleOutFileRedirection(t_var *var)
{
	t_tokens *tmp;

	tmp = var->tokens;
	while (tmp)
   {
		if (tmp && ft_strncmp(tmp->token, ">>", 2) == 0 )
    	{
			/* VAR->FLAG = 1; */
			var->std_out = dup(STDOUT_FILENO);
        	var->outfile = open(tmp->next->token, O_WRONLY | O_CREAT | O_APPEND);
			if (!var->outfile)
				printf("Minishell: No such file or directory: %s", tmp->next->token);
        	dup2(var->outfile, STDOUT_FILENO);
        	close(var->outfile);
    	}
    	else if (tmp && ft_strncmp(tmp->token, ">", 1) == 0 )
    	{
			/* VAR->FLAG = 1; */
			var->std_out = dup(STDOUT_FILENO);
        	var->outfile = open(tmp->next->token, O_WRONLY | O_CREAT);
			if (!var->outfile)
				printf("Minishell: No such file or directory: %s", tmp->next->token);
        	dup2(var->outfile, STDOUT_FILENO);
        	close(var->outfile);
    	}
		tmp = tmp->next;
	}
}
void    handleInFileRedirection(t_var *var)
{
	t_tokens *tmp;

	tmp = var->tokens;
	while (tmp)
    {
		if(tmp && ft_strncmp(tmp->token, "<", 1) == 0 )
    	{
        //  if(  tmp->token == '<' && pcmd->infile[0][1] == '<')
            // stdin = open_file(pcmd->name_tmp, O_RDONLY);
		/* 	VAR->FLAG = 2; */
			var->std_in = dup(STDIN_FILENO);
        	var->infile = open(tmp->next->token, O_RDONLY);
			if (!var->infile)
				printf("Minishell: No such file or directory: %s", tmp->next->token);
        	dup2(var->infile, STDIN_FILENO);
        	close(var->infile);
			ft_putendl_fd("Redir INPUT OK", 1);
    	}
		tmp = tmp->next;
	}
}