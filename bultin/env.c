/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohafnh <mohafnh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:36:16 by mohafnh           #+#    #+#             */
/*   Updated: 2023/10/24 19:08:36 by mohafnh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minshell.h"

int		env(t_env *env)
{
	while (env && env->next != NULL)
	{
		ft_putendl_fd(env->value, 1);
		env = env->next;
	}
	if (env)
		ft_putendl_fd(env->value, 1);
	return (1);
}