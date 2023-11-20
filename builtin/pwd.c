/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 03:41:02 by mohafnh           #+#    #+#             */
/*   Updated: 2023/11/02 17:13:40 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	pwd(char *path)
{
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
