/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohafnh <mohafnh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:04:21 by mohafnh           #+#    #+#             */
/*   Updated: 2023/10/17 19:25:32 by mohafnh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minshell.h"
void execute_command_cd( char *input) {
    // Divide la entrada en comando y argumentos
    char *comando = strtok(input, " \t\n"); // ****** se modificará *****
    char *argumento = strtok(NULL, " \t\n"); // ***** se modificará *****

    if (comando == NULL) {
        // No se ingresó un comando
        return;
    }

    if (strcmp(comando, "cd") == 0) {
        // Es el comando "cd", llama a la función cd con el argumento
        if (argumento != NULL) {
            char *error = cd(argumento);
            if (error != NULL) {
                fprintf(stderr, "Error: %s\n", error);
            }
        } else {
            fprintf(stderr, "Uso incorrecto: cd [ruta]\n");
        }
    } else {
        // Aquí puedes manejar otros comandos
        // Ejecutar otros comandos, mostrar un error si no son válidos, etc.
        printf("Comando: %s\n", comando);
    }
}


int main(int argc, char **argv) {
    const char *path = argv[1];
	if (!argv || argc != 1)
		return (EXIT_FAILURE);

    rl_initialize();
    run_shell();

    change_directory_relative_or_absolute(path);


    // obtener_dir();
    return 0;
}