#include "./include/minshell.h"

// Esta función ejecuta un comando con heredoc
void execute_command_with_heredoc() {
    int pipefd[2];
    create_pipe(pipefd);  // Crea una tubería para la comunicación entre procesos
    pid_t pid = create_child_process();  // Crea un proceso hijo

    if (pid == 0) {
        handle_child_process(pipefd);  // En el proceso hijo, maneja la ejecución del comando
    } else {
        handle_parent_process(pipefd);  // En el proceso padre, maneja la espera y el estado de salida del proceso hijo
    }

    close_pipe(pipefd);  // Cierra la tubería
}

// Crea una tubería para la comunicación entre procesos
void create_pipe(int pipefd[2]) {
    if (pipe(pipefd) == -1) {
        perror("Error al crear la tubería");  // En caso de error, muestra un mensaje de error y termina el programa
        exit(EXIT_FAILURE);
    }
}

// Crea un proceso hijo usando fork()
pid_t create_child_process() {
    pid_t pid;
    if ((pid = fork()) == -1) {
        perror("Error al crear el proceso hijo");  // En caso de error, muestra un mensaje de error y termina el programa
        exit(EXIT_FAILURE);
    }
    return pid;  // Devuelve el PID del proceso hijo
}

// En el proceso hijo, configura la entrada estándar y ejecuta el comando
void handle_child_process(int pipefd[2]) {
    close(pipefd[1]);  // Cierra el extremo de escritura de la tubería
    dup2(pipefd[0], STDIN_FILENO);  // Redirige la entrada estándar a partir de la tubería
    close(pipefd[0]);  // Cierra el extremo de lectura de la tubería

    char command[1024];
    ssize_t bytes_read;
    while ((bytes_read = read(STDIN_FILENO, command, sizeof(command))) > 0) {
        write(pipefd[1], command, bytes_read);  // Lee datos de la entrada estándar y los escribe en la tubería
    }

    exit(EXIT_SUCCESS);  // Sale con un estado de éxito
}

// En el proceso padre, espera a que el proceso hijo termine y muestra el estado de salida
void handle_parent_process(int pipefd[2]) {
    close(pipefd[0]);  // Cierra el extremo de lectura de la tubería

    int status;
    pid_t pid = wait(&status);  // Espera a que el proceso hijo termine y obtiene su estado de salida

    if (WIFEXITED(status)) {
        int exit_status = WEXITSTATUS(status);
        printf("Comando hijo con PID %d terminado con estado %d\n", pid, exit_status);  // Muestra el estado de salida del proceso hijo
    }
}

// Cierra la tubería
void close_pipe(int pipefd[2]) {
    close(pipefd[0]);
    close(pipefd[1]);
}

// Verifica si un comando es permitido
int is_comando_permitido(char* input) {
    char *comandos_validos[] = {
        "cd",
        "ls",
        "echo",
        NULL  // Un elemento nulo al final para indicar el final de la lista
    };

    int i = 0;
    while (comandos_validos[i] != NULL) {
        if (strcmp(input, comandos_validos[i]) == 0) {
            return 1;  // El comando es permitido
        }
        i++;
    }
    return 0;  // El comando no está permitido
}

// Esta función ejecuta un shell interactivo
void run_shell() {
    char *input = NULL;


    while (1) {
        input = readline("> ");  // Lee la entrada del usuario
        if (input == NULL) {
            break;  // Sale si se presiona Ctrl+D (EOF)
        }

        if (strlen(input) == 0) {
            free(input);
            continue;  // Salta si se ingresa una línea vacía
        }

        if (strcmp(input, "exit") == 0) {
            free(input);
            break;  // Sale si se ingresa "exit"
        }
        if (strcmp(input, "cd") == 0) {
            const char* path = input + 3;  // Salta "cd " para obtener la ruta
            const char* cd_result = cd(path);  // Llama a la función cd para cambiar de directorio
            if (cd_result != 0) {
                printf("Error al cambiar de directorio: %s\n", cd_result);  // Muestra un mensaje de error si no se puede cambiar de directorio
            }
            continue;  // No necesita ejecutar otros comandos después de "cd"
        }
        if (strcmp(input, "pwd") == 0) {
             char* path = input + 3;  // Salta "cd " para obtener la ruta
             int pwd_result =  pwd(path);  // Llama a la función cd para cambiar de directorio
            if (pwd_result != 0) {
                printf("Error al cambiar de directorio: %d\n", pwd_result);  // Muestra un mensaje de error si no se puede cambiar de directorio
            }
            continue;  // No necesita ejecutar otros comandos después de "cd"
        }
       
        // Agrega el comando al historial y ejecuta el comando
        add_history(input);
        execute_command_cd(input);
        free(input);
    }

    clear_history();  // Limpia el historial de Readline
}
