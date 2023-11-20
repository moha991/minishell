/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohafnh <mohafnh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:55:31 by mohafnh           #+#    #+#             */
/*   Updated: 2023/11/19 21:51:04 by mohafnh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"


/* void    executor(t_var *cmd, char **envp, int infile, int outfile)
{
    pid_t	pid;

	pid = ft_fork();
    if (pid == 0)
	{
		ft_infile(ps, infile);
		ft_outfile(ps, outfile);
		if (execve(ps->pth_cmd, ps->cmd, envp) == -1)
			exit(0);
	}
    
} */