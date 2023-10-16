/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohafnh <mohafnh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:08:09 by mohafnh           #+#    #+#             */
/*   Updated: 2023/10/16 12:42:54 by mohafnh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/minshell.h"


// Función personalizada para reemplazar la línea actual en Readline
void replace_line(const char *new_line)
{
    rl_on_new_line();  // Mueve el cursor al inicio de la línea
    clear_current_line(); // Borra la línea actual
    printf("%s", new_line); // Imprime la nueva línea
    rl_redisplay(); // Redibuja la línea
}

void clear_current_line() {
    printf("\r");  // Mueve el cursor al principio de la línea
    int i = 0;
    while (i < 80) {  // Suponiendo una longitud máxima de línea de 80 caracteres
        printf(" ");  // Imprime espacios en blanco para borrar la línea
        i++;
    }
    printf("\r");  // Mueve el cursor nuevamente al principio de la línea
}

// Función para ejecutar el comando 'cd' con una ruta relativa
void action_cd(const char *relative_path, char **start_directory) {
    // Obtén el directorio actual antes del cambio
    char current_directory[PATH_MAX];
    if (getcwd(current_directory, sizeof(current_directory)) == NULL) {
        perror("getcwd");
        return;
    }

    // Utiliza chdir para cambiar el directorio
    if (chdir(relative_path) == -1) {
        perror("cd"); // Manejo de errores si chdir falla
        return;
    }

    // Actualiza el directorio de inicio con el nuevo valor
    if (getcwd(*start_directory, sizeof(current_directory)) == NULL) {
        perror("getcwd");
    }
}
