/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohafnh <mohafnh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:52:26 by mohafnh           #+#    #+#             */
/*   Updated: 2023/11/16 11:10:21 by mohafnh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

char	*get_current_working_directory(char *cwd)
{
	cwd = getenv("PWD");
	if (cwd)
	{
		return (ft_strdup(cwd));

	}
	else
	{
		printf("error al obtener el directorio actual.\n ");
		return (NULL);
	}
}


size_t	ft_strspn(const char *str, const char *accept)
{
	const char	*s;
	const char	*a;
	size_t		count;

	s = str;
	count = 0;
	while (*s)
	{
		a = accept;
		while (*a)
		{
			if (*s == *a)
				break ;
			a++;
		}
		if (*a == '\0')
		{
			return (count);
		}
		count++;
		s++;
	}
	return (count);
}

t_tokens	*get_env(t_tokens *var, char *id)
{
	t_tokens	*tmp;

	if (!id)
		return (NULL);
	tmp = var;
	while (tmp)
	{
		if (ft_strcmp(tmp->token, id) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (-1);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	return (ft_strncmp(s1, s2, s1_len + s2_len));
}