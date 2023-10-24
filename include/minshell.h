/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohafnh <mohafnh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:50:53 by mohafnh           #+#    #+#             */
/*   Updated: 2023/10/24 17:21:06 by mohafnh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHEL_H
# define MINISHEL_H


# include <stdio.h>
#include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stddef.h> // Incluye la librería para definir NULL
# include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <errno.h>
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

// Macros to define quote
# define D_QUOTE '\"'
# define QUOTE '\''
# define D_QUOTE_S "\""
# define QUOTE_S "\'"

# define STARDIR "/home/usuario/"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define BUFF_SIZE 4096

typedef struct s_token
{
	char	*to_print;
	char	*to_exec;
	char	quote;
	char	*end;
	char	*new;
	int		i;
	int		init;
	int		len;
	int		posic;
}			t_token;

typedef struct {
    const char *command;
    void (*function)();
} CommandEntry;


typedef struct s_cmd
{
	char	*str;
	char	*flags;
	char	**args;
	
}	t_cmd;

typedef struct	s_env
{
	char			*value;
	struct s_env	*next;
}				t_env;



void execute_command_with_heredoc();
void create_pipe(int pipefd[2]);
pid_t create_child_process();
void handle_child_process(int pipefd[2]);
void handle_parent_process(int pipefd[2]);
void close_pipe(int pipefd[2]);
void run_shell();

// funciones de cd

void handle_cd_error(const char *path);
char *expand_tilde(const char *path);
int change_directory(const char *path);
char* cd(const char* path);

int change_directory(const char *path);
void change_directory_relative_or_absolute(const char *path);
void execute_command_cd( char *input);

// funciones de echo
void starts_with_echo(char **input_str);
void check_flags(char **args, int *flagecho);
void    run_builtin (t_cmd *input_cmd);

// funciones de pwd
int pwd(char *path);

// funciones de env
int		env(t_env *env);

// funciones de export
int add_new_env(const char *value, t_env *env);

// funciones de quoted
char* remove_quotes_from_word(const char* word);

# endif