/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:11:22 by mohafnh           #+#    #+#             */
/*   Updated: 2024/01/06 16:20:51 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static	int	error_identifier(char *identifier)
{
	ft_putstr_fd("Minishell: export: ", STDERR_FILENO);
	ft_putstr_fd(identifier, STDERR_FILENO);
	ft_putstr_fd(": not a valid identifier\n", STDERR_FILENO);
	return (1);
}

static	int	isvalid_namevar(char *name) //comprobar que el name de la variable sea alphanum o lowercase. 
{
	int	i;

	i = 0;
	if (!name)
		return (1);
	while (name[i] != '\0' && name[i] != '=')
    {
		if (!ft_isalnum(name[i]) && !(name[i] == '_'))
        	return (error_identifier(name), EXIT_FAILURE);
		i++;
	}
	return (0);
}

static	int append_to_env(t_var *var, char *expr, int flag)
{
	char	*name;
	int		exist_already;
	t_env	*tmp_node;
	
	exist_already = 0; // 0 esque no existe y 1 es que ya existe.
	while (expr[exist_already] != '=') //exist_already aqui se usa como iterador pero es solo para ahorrar variables luego se vuelve a poner a 0.
		exist_already++;
	name = ft_substr(expr, 0, exist_already);
	exist_already = 0;
	tmp_node = var->envp;
	while (tmp_node)
	{
		if (ft_strncmp(tmp_node->line_env, name, ft_strlen(name)) == 0)
		{
			if (!flag)
				tmp_node->line_env = expr;
			exist_already = 1;
			free(name);
		}
		tmp_node = tmp_node->next;
	}
	if (exist_already)
		return (0);
    // Allocate new node line content for env.
	ft_addback_node_env(&var->envp, new_node_env(expr));
	printf("has anadido $%s\n", expr);
	if (exist_already == 0)
		free(name);
    return (0);
}

static	int	show_values_alpha(t_var *var)
{
	char	**envp;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	envp = envlist_to_array(var->envp);
	while (envp[i])
	{
		j = 0;
		while (envp[j])
		{

			if (ft_strncmp(envp[i], envp[j], ft_strlen(envp[i])) < 0)
			{//printf("%s VA POR DELANTE DE %s\n", envp[j], envp[i]);
				tmp = envp[i];
				envp[i] = envp[j];
				envp[j] = tmp;
			}
			j++;
		}
		i++;
	}
	i = -1;
	while (envp[++i])
		ft_printf("declare -x %s\n", envp[i]);
	return (0);
}

// /* 
// export [name[=value]]
// */
int export(t_var *var)
{
    t_subnode 	*tmp;

	tmp = var->tokens->params;
	if (var->tokens->flags != NULL)
	{	
		printf("Minishell: export: no options can be handled.\n");
		return (1);
	}
	if (!tmp && !var->tokens->redir && !var->tokens->where_redir)
		return (show_values_alpha(var));  // ejecutar export sin args, mostrar env en orden alphabetico
	while (tmp)//iterar en los params del nodo export.
	{
		if (isvalid_namevar(tmp->content))// verificar que sea alphanum o '_'
		{
			printf("Minishell: export: Invalid identifier.\n");
			return (1);
		}
		if (ft_strchr(tmp->content, '='))
			append_to_env(var, tmp->content, 0);// anade la var_name con su valor.
		else
			append_to_env(var, tmp->content, 1); // anade la var_name sin valor
	}
	return (0);
}

