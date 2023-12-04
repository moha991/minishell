/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:35:31 by smagniny          #+#    #+#             */
/*   Updated: 2023/12/04 19:16:57 by smagniny         ###   ########.fr       */
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
	struct s_token_list	*next;
}	t_tokens;

typedef struct s_node_env
{
	char				*line_env;
	struct	s_node_env	*next;
}	t_env;

typedef struct s_var
{
	size_t		std_in;
	size_t		std_out;
	size_t		infile;
	size_t		outfile;
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
//redir func
void	handleOutFileRedirection(t_var *var);
void	handleInFileRedirection(t_var *var);
//moha
int		cd(t_tokens *tokens);
void	starts_with_echo(t_tokens *tokens);
t_tokens	*check_flags(t_tokens **tokens, int *flagecho);
void 	run_builtin(t_var *var);
int		pwd(char *path);
int		env(t_var *var);
int 	export(t_var *var);
void	unset(t_var *var);
#endif