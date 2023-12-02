/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:11:22 by mohafnh           #+#    #+#             */
/*   Updated: 2023/12/02 17:21:09 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static	int	error_identifier(char *identifier)
{
	ft_putstr_fd("minishell: export: `", STDERR_FILENO);
	ft_putstr_fd(identifier, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
	return (1);
}

static	int	isvalid_namevar(char *name) //comprobar que el name de la variable sea alphanum o lowercase. 
{
	int	i;

	i = 0;
	if (!name)
		return (1);
	while (name[i] != '\0')
    {
		if (!ft_isalnum(name[i]) && !(name[i] == '_'))
        	return (error_identifier(name), EXIT_FAILURE);
		i++;
	}
	return (0);
}

static	int append_to_env(t_var *var, char *name, char *value, int flag)
{
	char	*tmp;
	int		exist_already;
	t_env	*tmp_node;
	
	exist_already = 0; // 0 esque no existe y 1 es que ya existe.
	tmp = NULL;//frase a anadir
	tmp_node = var->envp;
	if (!flag)
		tmp = ft_strjoinfrees2(name, value);
	else
		tmp = name;
	while (tmp_node)
	{
		if (ft_strncmp(tmp_node->line_env, name, ft_strlen(name)) == 0)
		{
			if (!flag)
				tmp_node->line_env = tmp;
			exist_already = 1;
			free(name);
		}
		tmp_node = tmp_node->next;
	}
	if (exist_already)
		return (0);
    // Allocate new node line content for env.
	ft_addback_node_env(&var->envp, new_node_env(tmp));
	printf("has anadido $%s\n", tmp);
	if (exist_already == 0)
		free(name);
    return (0);
}

// /* 
// export [name[=value]]
// */

int export(t_var *var)
{
    char       	*var_name;
	char		*var_value;
    t_tokens 	*tokens;
    
	var_name = NULL;
	var_value = NULL;
	tokens = var->tokens->next; // token despues del token:'export' con el nombre de la var de entorno. (se supone, puede haber operador)
	if (!tokens || isdouble_operator(tokens->token, 0) || isingle_operator(tokens->token, 0))
		return (env(var));  // ejecutar export sin args, mostrar env.
	while (tokens && (!isdouble_operator(tokens->token, 0) || !isingle_operator(tokens->token, 0)))
	{
		if (isvalid_namevar(tokens->token))// verificar que sea alphanum o '_'
			return (1);
		printf("Valid name for export: [%s]\n", tokens->token);
		var_name = ft_strjoin(tokens->token, "=");
		tokens = tokens->next;// token '='
		if (tokens && ft_strncmp(tokens->token, "=", 1) == 0)
		{
			tokens = tokens->next; // string after '='. Is the value of var_name.
			var_value = ft_strdup(tokens->token);
			printf("Value of %s: [%s]\n", var_name, tokens->token);
			append_to_env(var, var_name, var_value, 0);// anade la var_name con su valor.
			tokens = tokens->next;
		}
		else
			append_to_env(var, var_name, var_value, 1); // anade la var_name sin valor
	}
	return (0);
}

