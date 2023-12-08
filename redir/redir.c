/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:03:39 by smagniny          #+#    #+#             */
/*   Updated: 2023/12/08 20:01:05 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void    base_redir(t_var *var)
{
	if (var->fd_in)
		close(var->fd_in);
	if (var->fd_out)
		close(var->fd_out);
	dup2(var->std_in, 0);
	close(var->std_in);
	dup2(var->std_out, 1);
	close(var->std_out);
}

void    handleOutFileRedirection(t_var *var)
{
	t_node		*tmp;
	t_subnode	*sub_redir_tmp;
	t_subnode	*sub_wheredir_tmp;
	tmp = var->tokens;
	if (tmp->redir == NULL || tmp->where_redir == NULL)
		return ;
	// todo esto me parece raro
	sub_redir_tmp = var->tokens->redir;
	while (sub_redir_tmp->next)
		sub_redir_tmp = sub_redir_tmp->next;
	sub_wheredir_tmp = var->tokens->where_redir;
	while (sub_wheredir_tmp->next)
		sub_wheredir_tmp = sub_wheredir_tmp->next;
	// hasta aqui
	//printf("redir executed: %s\nWhere_file founded: %s\n", sub_redir_tmp->content, sub_wheredir_tmp->content);
	if (ft_strncmp(sub_redir_tmp->content, ">>", 2) == 0)
	{
		var->std_out = dup(STDOUT_FILENO);
		var->fd_out = open(sub_wheredir_tmp->content, O_WRONLY | O_CREAT | O_APPEND);
		if (!var->fd_out)
			printf("Minishell: No such file or directory: %s", sub_wheredir_tmp->content);
		dup2(var->fd_out, STDOUT_FILENO);
		close(var->fd_out);
	}
	else if (tmp && ft_strncmp(sub_redir_tmp->content, ">", 1) == 0 )
	{
		var->std_out = dup(STDOUT_FILENO);
		var->fd_out = open(sub_wheredir_tmp->content, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (!var->fd_out)
			printf("Minishell: No such file or directory: %s", sub_wheredir_tmp->content);
		dup2(var->fd_out, STDOUT_FILENO);
		close(var->fd_out);
	}
}

// void    handleInFileRedirection(t_var *var)
// {
// 	t_node *tmp;

// 	tmp = var->tokens;
// 	while (tmp)
//     {
// 		if(tmp && ft_strncmp(tmp->token, "<", 1) == 0 )
//     	{
//         //  if(  tmp->token == '<' && pcmd->infile[0][1] == '<')
//             // stdin = open_file(pcmd->name_tmp, O_RDONLY);
// 		/* 	VAR->FLAG = 2; */
// 			var->std_in = dup(STDIN_FILENO);
//         	var->infile = open(tmp->next->token, O_RDONLY);
// 			if (!var->infile)
// 				printf("Minishell: No such file or directory: %s", tmp->next->token);
//         	dup2(var->infile, STDIN_FILENO);
//         	close(var->infile);
// 			ft_putendl_fd("Redir INPUT OK", 1);
//     	}
// 		tmp = tmp->next;
// 	}
// }