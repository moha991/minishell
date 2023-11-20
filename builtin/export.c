/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohafnh <mohafnh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:11:22 by mohafnh           #+#    #+#             */
/*   Updated: 2023/11/19 15:58:11 by mohafnh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/header.h"


int	special_char(char c) // mirar las validas bien 
{
    if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9') || (c == '_')))
	    return (0);
    else 
        return (1);
}

void	error_identifier(char *identifier)
{
	ft_putstr_fd("minishell: export: `", STDERR_FILENO);
	ft_putstr_fd(identifier, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
}

t_tokens	*new_env(char *id, char *value)
{
	t_tokens	*new;

	if (!id || !value)
		return (NULL);
    new = malloc(sizeof(t_tokens));
	if (!new)
		return (NULL);
    new->id = ft_strdup(id);
    new->token = value;
	new->next = NULL;
	return (new);
}


t_tokens	*set_env(t_tokens **env, char *id, char *value)
{
	t_tokens	*new;
	t_tokens	*last;

	new = get_env(*env, id);
	if (new)
	{
		free(new->token);
		new->token = value;
		return (new);
	}
	new = new_env(id, value);
	if (!new)
		return (NULL);
	if (*env)
	{
		last = *env;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*env = new;
	return (new);
}

/* int export(t_var *var)
{
    int	i;
    t_tokens *tokens;
    char       *id;
    
    
    i = 0;
    id = NULL;
    tokens = var->tokens->next;
    while(tokens && tokens->token[i])
    {
        while (tokens && tokens->token[i] != '=')
        {
            if (special_char(tokens->token[i]))
                return (error_identifier(&tokens->token[i]), EXIT_FAILURE);
            i++;
        }
        if (i == 0)
			return (error_identifier(&tokens->token[i]), EXIT_FAILURE);
        id = ft_substr(tokens->token, 0, i);
        if (tokens->token[i])
		{
			tokens->token[i] = '\0';
			if (!set_env(env, id, ft_strdup(&tokens->token[i + 1])))
				return (EXIT_FAILURE);
		}
		i++;
    }
    return (EXIT_SUCCESS);
} */