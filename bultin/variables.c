/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohafnh <mohafnh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:16:04 by mohafnh           #+#    #+#             */
/*   Updated: 2023/10/20 15:16:19 by mohafnh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minshell.h"


char *process_environment_variables(char *word) {
    // Reservar memoria para la palabra de resultado, con el tamaño de la palabra original más un carácter nulo
    char *result = malloc(strlen(word) + 1);

    // Verificar si la asignación de memoria fue exitosa
    if (result == NULL) {
        fprintf(stderr, "Error de asignación de memoria\n");
        exit(EXIT_FAILURE);
    }

    int result_index = 0; // Índice actual en la palabra de resultado
    int word_index = 0; // Índice actual en la palabra original

    // Recorrer la palabra original hasta encontrar el carácter nulo (fin de la cadena)
    while (word[word_index] != '\0') {
        if (word[word_index] == '$' && word[word_index + 1] == '{') {
            // Encontramos el inicio de una variable de entorno
            word_index += 2;
            int variable_start = word_index;

            // Buscar el final de la variable (carácter '}')
            while (word[word_index] != '}' && word[word_index] != '\0') {
                word_index++;
            }

            if (word[word_index] == '}') {
                // Hemos encontrado el final de la variable
                // Extraer el nombre de la variable y copiarla en variable_name
                char variable_name[word_index - variable_start + 1];
                strncpy(variable_name, word + variable_start, word_index - variable_start);
                variable_name[word_index - variable_start] = '\0';

                // Obtener el valor de la variable de entorno
                char *env_value = getenv(variable_name);
                if (env_value != NULL) {
                    // La variable de entorno existe y tiene un valor
                    // Copiar su valor en la palabra de resultado
                    strcpy(result + result_index, env_value);
                    result_index += strlen(env_value);
                }
            }

            if (word[word_index] == '\0') {
                // Llegamos al final de la palabra
                break;
            }
        } else {
            // Copiar el carácter actual a la palabra de resultado
            result[result_index] = word[word_index];
            result_index++;
        }

        word_index++;
    }

    // Agregar el carácter nulo al final de la palabra de resultado
    result[result_index] = '\0';

    return result;
}
