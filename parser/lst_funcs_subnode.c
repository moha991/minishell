/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funcs_subnode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:11:33 by smagniny          #+#    #+#             */
/*   Updated: 2023/12/06 18:27:33 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void ft_lstclear_subnode(t_subnode **lst)
{
    t_subnode *current;

    if (!lst || !*lst)
        return;

    while (*lst)
    {
        current = *lst;
        *lst = (*lst)->next;
        free(current->content);
        free(current);
    }
}

t_subnode	*ft_lstnew_subnode(char *content)
{
	t_subnode    *ptr;

	ptr = (t_subnode *)malloc(sizeof(t_subnode));
	if (!(ptr))
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

t_subnode	*ft_lstlast_subnode(t_subnode *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_subnode(t_subnode **lst, t_subnode *new)
{	
	t_subnode	*ptr;

	ptr = ft_lstlast_subnode(*lst);
	if (ptr != NULL)
		ptr->next = new;
	else
		*lst = new;
}