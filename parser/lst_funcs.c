/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:19:53 by smagniny          #+#    #+#             */
/*   Updated: 2023/10/30 17:59:48 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void ft_lstcleartok(t_tokens **lst)
{
    t_tokens *current;

    if (!lst || !*lst)
        return;

    while (*lst)
    {
        current = *lst;
        *lst = (*lst)->next;
        free(current->token);
        free(current);
    }
}

t_tokens	*ft_lstnewtok(char *content)
{
	t_tokens    *ptr;

	ptr = (t_tokens *)malloc(sizeof(t_tokens));
	if (!(ptr))
		return (NULL);
	ptr->token = content;
	ptr->next = NULL;
	return (ptr);
}

t_tokens	*ft_lstlasttok(t_tokens *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_backtok(t_tokens **lst, t_tokens *new)
{	
	t_tokens	*ptr;

	ptr = ft_lstlasttok(*lst);
	if (ptr != NULL)
		ptr->next = new;
	else
		*lst = new;
}
