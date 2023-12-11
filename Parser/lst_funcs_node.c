/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funcs_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:19:53 by smagniny          #+#    #+#             */
/*   Updated: 2023/12/08 19:19:45 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void ft_lstclear_node(t_node **lst)
{
    t_node *current;

    if (!lst || !*lst)
        return;

    while (*lst)
    {
        current = *lst;
        *lst = (*lst)->next;
		if (current->token != NULL)
        	free(current->token);
		if (current->flags != NULL)
			ft_lstclear_subnode(&current->flags);
		if (current->params != NULL)
			ft_lstclear_subnode(&current->params);
		if (current->redir != NULL)
			ft_lstclear_subnode(&current->redir);
		if (current->where_redir != NULL)
			ft_lstclear_subnode(&current->where_redir);
        free(current);
    }
}

t_node	*ft_lstnew_node(char *content)
{
	t_node    *ptr;

	ptr = (t_node *)malloc(sizeof(t_node));
	if (!(ptr))
		return (NULL);
	ptr->token = content;
	ptr->flags = NULL;
	ptr->params = NULL;
	ptr->redir = NULL;
	ptr->where_redir = NULL;
	ptr->next = NULL;
	return (ptr);
}

t_node	*ft_lstlast_node(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_node(t_node **lst, t_node *new)
{	
	t_node	*ptr;

	ptr = ft_lstlast_node(*lst);
	if (ptr != NULL)
		ptr->next = new;
	else
		*lst = new;
}
