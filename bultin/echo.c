/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohafnh <mohafnh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:07:23 by mohafnh           #+#    #+#             */
/*   Updated: 2023/10/20 14:56:57 by mohafnh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/minshell.h"

int starts_with_echo(const char *input) {
    return strncmp(input, "echo", 4) == 0;
}


// Función para dividir la cadena de entrada en palabras
char **split_input_into_words(const char *input) {
    char **words = NULL; // Array de punteros a cadenas (las palabras)
    size_t word_count = 0; // Contador de palabras

    const char *delimiters = " \t\n"; // Delimitadores de palabras: espacio, tabulador y nueva línea
    char *input_copy = ft_strdup(input); // Copia la cadena de entrada para trabajar con ella sin modificar la original
    char *token = ft_strtok(input_copy, delimiters); // Inicializa el tokenizador con la cadena copiada **** modificar esta parte*****

    while (token != NULL) { // Mientras haya tokens (palabras) para procesar
        words = ft_realloc(words, (word_count + 1) * sizeof(char *)); // Reasigna memoria para la nueva palabra
        words[word_count] = ft_strdup(token); // Almacena la palabra en el array
        word_count++; // Incrementa el contador de palabras
        token = ft_strtok(NULL, delimiters); // Obtiene el siguiente token
    }

    ft_free(input_copy); // Libera la memoria de la copia de la cadena
    words = ft_realloc(words, (word_count + 1) * sizeof(char *)); // Añade un elemento nulo al final para marcar el fin de la lista de palabras
    words[word_count] = NULL; // Marca el final de la lista de palabras con un puntero nulo

    return words; // Retorna el array de palabras
}
