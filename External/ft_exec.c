/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:01:41 by smagniny          #+#    #+#             */
/*   Updated: 2023/12/11 18:38:52 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static	char	**malloc_flagsandparams_node(t_node *node)
{
	t_subnode   *tmp;
	int			size;
	char		**args;

	tmp = node->flags;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	tmp = node->params;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	args = (char **)malloc((size + 2) * sizeof(char *));
	if (!args)
		return (NULL);
	return (args);
}

static	char	**set_flagsandparams_to_array(t_node *node)
{
	t_subnode   *tmp;
	char		**args;
	int			i;

	args = malloc_flagsandparams_node(node);
	tmp = node->flags;
	i = 0;
	args[i++] = ft_strdup(node->token);
	while (tmp)
	{
		args[i++] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	tmp = node->params;
	while (tmp)
	{
		args[i++] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	args[i] = NULL;
	return (args);
}

static	char	**envlist_to_array(t_env *envlist)
{
	char	**envp;
    t_env 	*tmp;
	int 	count;
	int		i;

	i = 0;
	count = 0;
	tmp = envlist;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
	envp = (char **)malloc((count + 1) * sizeof(char *));
	tmp = envlist;
	while (i < count)
	{
		envp[i++] = ft_strdup(tmp->line_env);
		tmp = tmp->next;
	}
	envp[i] = NULL;
	return (envp);
}

static	char	**find_path_env(char **envp)
{
	int		i;
	char	**tmp;

	i = 0;
	while (ft_strncmp("PATH=", envp[i], 5) != 0)
		i++;
	tmp = ft_split(envp[i] + 5, ':');
	return (tmp);
}

static	char	*find_path(char **envp, char	*command)
{
	char	*path;
	char	*ppath;
	char	**tmp;
	int		i;

	if (!command || command == NULL)
		return (NULL);
	if (access(command, X_OK | F_OK) == 0)
		return (command);
	tmp = find_path_env(envp);
	i = -1;
	while (tmp[++i] && command)
	{
		ppath = ft_strjoin(tmp[i], "/");
		path = ft_strjoin(ppath, command);
		free(ppath);
		if (access(path, X_OK) == 0)
		{
			doublefree(tmp);
			return (path);
		}
		free(path);
	}
	doublefree(tmp);
	return (NULL);
}

void	ft_exec(t_var *var)
{
	pid_t	pid;
	char    **args;
	char	**envp;
	char	*exec_path;
	// int		fd[2];

	// if (pipe(fd) == -1)
	// 	panic("Minishell: cannot create Pipe", 127);
	args = set_flagsandparams_to_array(var->tokens);
	// i = -1;
	// while (args[++i])
	// 	printf("operation[%d]: %s\n", i, args[i]);
	envp = envlist_to_array(var->envp);
	// i = -1;
	// while (envp[++i])
	// 	printf("envp[%d]: %s\n", i, envp[i]);
	exec_path = find_path(envp, var->tokens->token);
	// printf("exec_path found: %s\n", exec_path);
	if (exec_path == NULL)
	{
		doublefree(envp);
		doublefree(args);
		printf("Minishell: Invalid command\n");
		return ;
	}
	pid = fork();
	if (pid < 0)
	{
		free(exec_path);
		doublefree(envp);
		doublefree(args);
		printf("Minishell: ERROR: Cannot create new process\n");
		return ;
	}
	if (pid == 0)
	{
		// close(fd[0]);
		// dup2(fd[1], STDOUT_FILENO);
		// close(fd[1]);
		if (execve(exec_path, args, envp) == -1)
		{
			free(exec_path);
			doublefree(envp);
			doublefree(args);
			printf("Minishell: execve failed\n");
			return ;
		}
	}
	// else
	// {
	// 	close(fd[1]);
	// 	dup2(fd[0], STDIN_FILENO);
	// 	close(fd[0]);
	// }
	// close(fd[1]);
	// close(fd[0]);
	waitpid(pid, 0, 0);
	free(exec_path);
	doublefree(envp);
	doublefree(args);
}