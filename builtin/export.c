/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:11:22 by mohafnh           #+#    #+#             */
/*   Updated: 2023/12/01 17:48:51 by smagniny         ###   ########.fr       */
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
	char 	**new_env;
	int		env_count;
	int		i;
	char	*tmp;
	int		exist_already;

	env_count = 0; //primer contador
	i = -1; //segunda contador
	exist_already = 0; // 0 esque no existe y 1 es que ya existe.
	tmp = NULL;//frase a anadir
	new_env = NULL;// puntero de nuevas var entorno.
	if (!flag)
		tmp = ft_strjoinfrees2(name, value);
	else
		tmp = name;
	while (var->envp[env_count])
	{
		if (ft_strncmp(var->envp[env_count], name, ft_strlen(name)) == 0)
		{
			if (!flag)
				var->envp[env_count] = tmp;
			exist_already = 1;
			free(name);
		}
		env_count++;
	}
	if (exist_already)
	{
		printf("has actualizado $%s\n", tmp);
		return (0);
	}
    // Allocate
    new_env = (char **)malloc((env_count + 2) * sizeof(char *));
    if (!new_env)
	{
        perror("malloc\n");
        exit(EXIT_FAILURE);
	}
	while (++i < env_count)
		new_env[i] = var->envp[i];
    // anadir linea
    new_env[env_count] = tmp;
    new_env[env_count + 1] = NULL;
	printf("has anadido $%s\n", tmp);
	if (!exist_already)
		free(name);
    // actualizar puntero original
	doublefree(var->envp);
    var->envp = new_env;
    return ();
}

/* 
export [name[=value]]
*/

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

