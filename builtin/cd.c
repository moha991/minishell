/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:34:27 by mohafnh           #+#    #+#             */
/*   Updated: 2023/10/25 12:30:54 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/header.h"

// Función para manejar errores de 'cd'
void handle_cd_error(const char *path) {
    // Esta función se encarga de manejar errores relacionados con 'cd'.
    // Imprime un mensaje de error que indica el problema y usa perror() para mostrar detalles.
    fprintf(stderr, "Error en 'cd' al acceder a '%s': ", path);
    perror(NULL);  // El parámetro NULL se usa para imprimir un mensaje de error del sistema.
}


// Función para expandir '~' a la ruta de inicio del usuario
char *expand_tilde(const char *path) {
    // Esta función expande el carácter '~' al directorio de inicio del usuario.
    // Si el path comienza con '~', se reemplaza '~' con el directorio de inicio.
    if (path[0] == '~') {
        char *home = getenv("HOME");  // Obtener el directorio de inicio del usuario desde la variable de entorno 'HOME'.
        if (home == NULL) {
            // Si 'HOME' no está definida, imprime un mensaje de error y retorna NULL.
            fprintf(stderr, "Variable de entorno 'HOME' no definida.\n");
            return NULL;
        }
        // Reservar memoria para la ruta expandida.
        char *expanded = (char *)malloc(strlen(home) + strlen(path) - 1);
        if (expanded == NULL) {
            perror("malloc");
            return NULL;
        }
        // Construir la ruta expandida concatenando 'home' y el resto de la ruta después de '~'.
        sprintf(expanded, "%s%s", home, path + 1);
        return expanded;  // Retorna la ruta expandida.
    }
    return strdup(path);  // Si no comienza con '~', simplemente se duplica la ruta original y se retorna.
}
int change_directory(const char *path) {
    // Esta función cambia el directorio actual al 'path' proporcionado.
    // Si hay algún error, muestra un mensaje de error y retorna 1, de lo contrario, retorna 0.

    // Intenta cambiar el directorio con chdir().
    if (chdir(path) == -1) {
        perror("Error al cambiar de directorio");
        return 1;
    }

    // Obtiene el directorio actual después de cambiarlo.
    char current_dir[PATH_MAX];
    if (getcwd(current_dir, sizeof(current_dir)) == NULL) {
        perror("getcwd");
        return 1;
    }

    // Actualiza la variable de entorno 'PWD' con el nuevo directorio actual.
    if (setenv("PWD", current_dir, 1) == -1) {
        perror("setenv");
        return 1;
    }

    return 0;  // Retorna 0 para indicar que el cambio de directorio fue exitoso.
}


void change_directory_relative_or_absolute(const char *path) {
    // Esta función decide si el cambio de directorio debe ser relativo o absoluto
    // y llama a 'change_directory' para realizar el cambio.

    if (path[0] == '/') {
        // Si el 'path' comienza con '/', es una ruta absoluta, por lo que simplemente llama a 'change_directory'.
        if (change_directory(path) == 0) {
            printf("Cambiado al directorio: %s\n", path);  // Muestra un mensaje de éxito.
        }
    } else {
        // Si el 'path' no comienza con '/', es una ruta relativa.
        char current_dir[PATH_MAX];
        if (getcwd(current_dir, sizeof(current_dir)) == NULL) {
            perror("getcwd");
            return;  // Muestra un mensaje de error y retorna si no se puede obtener el directorio actual.
        }

        char new_dir[PATH_MAX];
        // Construye la nueva ruta concatenando el directorio actual y el 'path' relativo.
        ft_printf(new_dir, sizeof(new_dir), "%s/%s", current_dir, path); // **** se modificara ******

        if (change_directory(new_dir) == 0) {
            printf("Cambiado al directorio: %s\n", new_dir);  // Muestra un mensaje de éxito.
        }
    }
}

char* cd(const char* path) {
    // Esta función se utiliza para cambiar de directorio.
    // Expande la tilde si está presente, luego llama a 'change_directory_relative_or_absolute' para realizar el cambio.

    char* expanded_path = expand_tilde(path);
    if (expanded_path == NULL) {
        // Si no se pudo expandir la tilde, retorna un mensaje de error.
        return "Error al expandir la tilde.";
    }

    // Realiza el cambio de directorio basado en la ruta expandida.
    change_directory_relative_or_absolute(expanded_path);

    free(expanded_path);  // Libera la memoria utilizada para la ruta expandida.

    return NULL;  // Retorna NULL para indicar que el cambio de directorio fue exitoso.
}
