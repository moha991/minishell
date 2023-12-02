/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:35:31 by smagniny          #+#    #+#             */
/*   Updated: 2023/12/02 18:11:48 by smagniny         ###   ########.fr       */
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
	char				*token;
	char				*id;
	struct s_token_list	*next;
}	t_tokens;

typedef struct s_node_env
{
	char				*line_env;
	struct	s_node_env	*next;
}	t_env;

typedef struct s_var
{
	char		**cmd;		//bloque cmd
	char		**infile;	//bloque de entrada
	char		**outfile;	//bloque de salida
	char		**dl_hd;	//Delmitadores el heredoc
	char		*tmp;		//nombre dle archivo tmp
	t_env		*envp;
	char		*inputline;
	int			len_inputline;
	t_tokens	*tokens;
}	t_var;


//santi
//lexer
void	lexer(t_var *var);
int		is_space_or_eof(int c);
int		isingle_operator(char *line, int i);
int		isdouble_operator(char *line, int i);
int		issinglequote(int c);
int		isdoublequote(int c);
char	*ft_strjoinfreee(char *s1, char *s2);
char	*get_str_doublequoted(t_var *var, int *i, int *start);
char	*get_str_singlequoted(t_var *var, int *i, int *start);
char	*get_word(t_var *var, int *i, int *start);
//list tokenizer functions
t_tokens	*ft_lstnewtok(char *content);
void		ft_lstadd_backtok(t_tokens **lst, t_tokens *new);
t_tokens	*ft_lstlasttok(t_tokens *lst);
void 		ft_lstcleartok(t_tokens **lst);
//list environment functions
void	cpy_env(t_env **ptr, const char **envp);
void 	ft_freeenv(t_env **lst);
t_env   *new_node_env(const char *line_env);
void	ft_addback_node_env(t_env **lst, t_env *new);
//moha
void		execute_command_with_heredoc();
void		create_pipe(int pipefd[2]);
pid_t		create_child_process();
void		handle_child_process(int pipefd[2]);
void	handle_parent_process(int pipefd[2]);
void	close_pipe(int pipefd[2]);
void		run_shell();

// funciones de cd
int		cd(t_tokens *tokens);

// funciones de echo
void	starts_with_echo(t_tokens *tokens);
t_tokens	*check_flags(t_tokens **tokens, int *flagecho);
void 	run_builtin(t_var *var);
int	check_flagn(t_tokens **tokens);

// funciones de pwd
int		pwd(char *path);

// funciones de env
int		env(t_var *var);

// funciones de export
int export(t_var *var);

void	unset(t_var *var);
// funciones de quoted
char	*remove_quotes_from_word(const char	*word);

// funciones utiles 
size_t	ft_strspn(const char *str, const char *accept);

t_tokens	*get_env(t_tokens *var, char *id);
t_tokens	*set_env(t_tokens **env, char *id, char *value);
int	ft_strcmp(const char *s1, const char *s2);

// Funciones executor



// funciones utiles executor
// funciones de quoted
#endif