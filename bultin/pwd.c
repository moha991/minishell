/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohafnh <mohafnh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 03:41:02 by mohafnh           #+#    #+#             */
/*   Updated: 2023/10/24 10:07:52 by mohafnh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minshell.h"

int pwd(char *path)
{
    
   path = getcwd(NULL, 0);

    if (path == NULL)
    {
        perror("Error al obtener el directorio actual");
        return 1;
    }

    printf("%s\n", path);
    free(path);
    return 0;
}