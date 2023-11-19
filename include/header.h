/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:35:31 by smagniny          #+#    #+#             */
/*   Updated: 2023/11/19 17:11:06 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <errno.h>
# include "libft/libft.h"
# include <string.h>
# include <unistd.h>

//moha includes
# include <stddef.h> // Incluye la librería para definir NULL
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>


# define SINGLEQ '\''
# define DOUBLEQ '\"'

typedef struct s_token_list
{
	char	*token;
	struct s_token_list *next;
}	t_tokens;


typedef struct s_var
{
	char		**envp; //meter contenido del doble puntero a una lista enlazada de struct t_env
	char		*inputline;
	int			len_inputline;
	t_tokens	*tokens;
	int			nb_tokens;
}	t_var;


// typedef struct s_cmd
// {
// 	char	*str;
// 	char	*flags;
// 	char	**args;
// }	t_cmd;


//santi

void	lexer(t_var *var);
int		is_space_or_eof(int c);
int		isingle_operator(char *line, int i);
int		isdouble_operator(char *line, int i);
int		issinglequote(int c);
int		isdoublequote(int c);
int		isallowedchar(int c);
char	*ft_strjoinfreee(char *s1, char *s2);
char	*get_str_doublequoted(t_var *var, int *i, int *start);
char	*get_str_singlequoted(t_var *var, int *i, int *start);
char	*get_word(t_var *var, int *i, int *start);
//list tokenizer functions
t_tokens	*ft_lstnewtok(char *content);
void		ft_lstadd_backtok(t_tokens **lst, t_tokens *new);
t_tokens	*ft_lstlasttok(t_tokens *lst);
void 		ft_lstcleartok(t_tokens **lst);

//moha

// funciones de cd

void handle_cd_error(const char *path);
char *expand_tilde(const char *path);
int change_directory(const char *path);
char* cd(const char* path);

void change_directory_relative_or_absolute(const char *path);

// funciones de echo
void	starts_with_echo(char **input_str);
void check_flags(char **args, int *flagecho);

// funciones de pwd
int pwd(char *path);

// funciones de env
// int		env(t_env *env);

// funciones de export
// int add_new_env(const char *value, t_env *env);

// funciones de quoted
#endif