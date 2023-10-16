#include "./include/minshell.h"

void execute_command_with_heredoc() {
    int pipefd[2];
    create_pipe(pipefd);
    pid_t pid = create_child_process();

    if (pid == 0) {
        handle_child_process(pipefd);
    } else {
        handle_parent_process(pipefd);
    }

    close_pipe(pipefd);
}

void create_pipe(int pipefd[2]) {
    if (pipe(pipefd) == -1) {
        perror("Error al crear la tubería");
        exit(EXIT_FAILURE);
    }
}

pid_t create_child_process() {
    pid_t pid;
    if ((pid = fork()) == -1) {
        perror("Error al crear el proceso hijo");
        exit(EXIT_FAILURE);
    }
    return pid;
}

void handle_child_process(int pipefd[2]) {
    close(pipefd[1]);
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);

    char command[1024];
    ssize_t bytes_read;
    while ((bytes_read = read(STDIN_FILENO, command, sizeof(command))) > 0) {
        write(pipefd[1], command, bytes_read);
    }

    exit(EXIT_SUCCESS);
}

void handle_parent_process(int pipefd[2]) {
    close(pipefd[0]);

    int status;
    pid_t pid = wait(&status);

    if (WIFEXITED(status)) {
        int exit_status = WEXITSTATUS(status);
        printf("Comando hijo con PID %d terminado con estado %d\n", pid, exit_status);
    }
}


void close_pipe(int pipefd[2]) {
    close(pipefd[0]);
    close(pipefd[1]);
}



void execute_command(char *input) {
    char* cmd = "/bin/sh";
    char* args[] = { "sh", "-c", input, NULL };

    pid_t pid = fork();
    if (pid == -1) {
        perror("Error al crear el proceso hijo");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        execve(cmd, args, NULL);
        perror("Error en execve");
        exit(EXIT_FAILURE);
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}

int is_comando_permitido(char* input) {
    char *comandos_validos[] = {
        "cd",
        NULL // Un elemento nulo al final para indicar el final de la lista
    };

    int i = 0;
    while (comandos_validos[i] != NULL) {
        if (strcmp(input, comandos_validos[i]) == 0) {
            return 1; // El comando es permitido
        }
        i++;
    }
    return 0; // El comando no está permitido
}




void run_shell() {
char *input;
char* start_directory = STARDIR;

    while (1) {
        input = readline("> ");
        if (input == NULL) {
            break; // Salir si se presiona Ctrl+D (EOF)
        }

        if (strlen(input) == 0) {
            free(input);
            continue; // Saltar si se ingresa una línea vacía
        }

        if (strcmp(input, "exit") == 0) {
            free(input);
            break; // Salir si se ingresa "exit"
        }
       if (strcmp(input, "cd") == 0) {
            char relative_path[PATH_MAX]; // Aquí debes proporcionar la ruta relativa
            action_cd(relative_path, &start_directory);
        }

       if (!is_comando_permitido(input)) {
        printf("Comando no permitido: %s\n", input);
        free(input);
        continue;
        }

        add_history(input); // Agregar el comando al historial
        execute_command(input);
        free(input);
    }

        clear_history(); // Limpiar el historial de Readline
}