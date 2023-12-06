/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 03:41:02 by mohafnh           #+#    #+#             */
/*   Updated: 2023/12/06 18:00:02 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	pwd(t_var	*var)
{
	char	*path;

	//verificar var->tokens para mirar que no haya flags ni params.
	(void)var;
	path = getcwd(NULL, 0);
	if (path == NULL)
	{
		perror("Error al obtener el directorio actual");
		return (1);
	}
	printf("%s\n", path);
	free(path);
	return (0);
}
