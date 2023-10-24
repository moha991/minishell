/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohafnh <mohafnh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:11:22 by mohafnh           #+#    #+#             */
/*   Updated: 2023/10/24 19:05:57 by mohafnh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/minshell.h"

int add_new_env(char **env, const char *value) {
    // 1. Calcula el número de variables de entorno actuales.
    int env_count = 0;
    while (env[env_count] != NULL) {
        env_count++;
    }

    // 2. Crea un nuevo arreglo que sea una copia del original con espacio adicional para la nueva variable.
    char **new_env = (char **)malloc(sizeof(char *) * (env_count + 2));  // +2 para la nueva variable y NULL final
    if (!new_env) {
        return -1; // Error de asignación de memoria.
    }

    // 3. Copia las variables de entorno originales al nuevo arreglo.
    int i = 0;
    while (i < env_count) {
        new_env[i] = strdup(env[i]);
        if (!new_env[i]) {
            return -1; // Error de asignación de memoria.
        }
        i++;
    }

    // 4. Agrega la nueva variable de entorno al final del nuevo arreglo.
    new_env[env_count] = strdup(value);
    if (!new_env[env_count]) {
        return -1; // Error de asignación de memoria.
    }

    // 5. Establece el último elemento del nuevo arreglo como NULL para indicar el final.
    new_env[env_count + 1] = NULL;

    // 6. Libera la memoria del antiguo arreglo.
    i = 0;
    while (i < env_count) {
        free(env[i]);
        i++;
    }
    free(env);

    // 7. Asigna el nuevo arreglo a la variable de entorno original.
    *env = new_env;

    // 8. Devuelve 0 para indicar que la operación de agregar fue exitosa.
    return 0;
}
