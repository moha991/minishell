/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohafnh <mohafnh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:50:53 by mohafnh           #+#    #+#             */
/*   Updated: 2023/10/16 15:21:22 by mohafnh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHEL_H
# define MINISHEL_H


# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>
# include "../libft/srcs/libft.h"
# include "../libft/srcs/get_next_line.h"

# define EMPTY 0
# define CMD 1
# define ARG 2
# define TRUNC 3
# define APPEND 4
# define INPUT 5
# define PIPE 6
# define END 7

# define STARDIR "/home/usuario/"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define BUFF_SIZE 4096

typedef struct {
    const char *command;
    void (*function)();
} CommandEntry;


void clear_current_line();
void execute_command_with_heredoc();
void create_pipe(int pipefd[2]);
pid_t create_child_process();
void handle_child_process(int pipefd[2]);
void handle_parent_process(int pipefd[2]);
void close_pipe(int pipefd[2]);
void execute_command(char *input);
void run_shell();
void action_cd(const char *relative_path, char **start_directory);
void replace_line(const char *new_line);




# endif