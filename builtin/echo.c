/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohafnh <mohafnh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:07:23 by mohafnh           #+#    #+#             */
/*   Updated: 2023/11/13 17:28:17 by mohafnh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	starts_with_echo(t_tokens *tokens)
{
	int		flagecho;
	char	*start;

	flagecho = 0;
	tokens = tokens->next;
	tokens = check_flags(&tokens, &flagecho);
	while (tokens)
	{
		start = tokens->token;
		if (flagecho == 0)
		{
			printf("%s", start);
			printf(" ");
		}
		if (flagecho == 1)
		{
			printf("%s", start);
			printf(" ");
		}
		tokens = tokens->next;
	}
	if (flagecho == 0)
		printf("\n");
}

t_tokens	*check_flags(t_tokens **tokens, int *flagecho)
{
	int 	count;
	
	count = 0;
	if ((*tokens)->token[count] == '-')
	{
		count++;
		while ((*tokens)->token[count] == 'n')
			count++;				
		if ((*tokens)->token[count] != '\0')
			*flagecho = 0;
		else
		{	
			*flagecho = 1;
			(*tokens) = (*tokens)->next;
		}
	}
	if (*flagecho == 1)
	{
		while ((*tokens))
		{
			count = 0;
			if ((*tokens)->token[count] == '-')
			{
				count++;
				while ((*tokens)->token[count] == 'n')
					count++;
				if ((*tokens)->token[count] != '\0')
					break;
				else
					(*tokens) = (*tokens)->next;
			}
			else
				break ;
		}
	} 
	return (*tokens);
}
