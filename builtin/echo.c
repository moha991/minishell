/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:07:23 by mohafnh           #+#    #+#             */
/*   Updated: 2023/10/25 12:33:30 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

// Función para imprimir los argumentos y verificar el uso de -n en el comando
void    starts_with_echo(char **input_str) {
    int i = 0;
    int flagecho = 1;  // Inicialmente, consideramos que no hay -n

    check_flags(input_str, &flagecho);

    // Iterar a través de los argumentos e imprimirlos
    while (input_str[i]) {
        printf("%s", input_str[i]);
        i++;
    }

    if (flagecho) {
        printf("\n");
    }
	// return (input_str);
}

// Función para verificar si se usa -n en los argumentos
void check_flags(char **args, int *flagecho) {
    int i;
    
    i = 0;

    // Iterar a través de los argumentos y verificar si alguno comienza con -n
    while (args[i]) {
        if (!ft_strncmp(args[i], "-n", 2)) {
            *flagecho = 0;  // Se encontró -n, establece flagecho en 0
            break;  // Puedes detenerte una vez que se encuentra -n
        }
        i++;
    }
}
