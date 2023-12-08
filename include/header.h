/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:35:31 by smagniny          #+#    #+#             */
/*   Updated: 2023/12/08 18:48:04 by smagniny         ###   ########.fr       */
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

typedef struct s_subnode
{
	char				*content;
	struct s_subnode	*next;
}	t_subnode;

typedef struct s_node
{
	char				*token;
	t_subnode			*flags;
	t_subnode			*params;
	t_subnode			*redir;
	t_subnode			*where_redir;
	struct s_node		*next;
}	t_node;

typedef struct s_node_env
{
	char				*line_env;
	struct	s_node_env	*next;
}	t_env;

typedef struct s_var
{
	size_t		std_in;
	size_t		std_out;
	size_t		fd_in;
	size_t		fd_out;
	t_env		*envp;
	char		*inputline;
	int			len_inputline;
	t_node		*tokens;
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
//list node functions
void 		ft_lstclear_node(t_node **lst);
t_node		*ft_lstnew_node(char *content);
t_node		*ft_lstlast_node(t_node *lst);
void		ft_lstadd_back_node(t_node **lst, t_node *new);
//list subnode functions
void 		ft_lstclear_subnode(t_subnode **lst);
t_subnode	*ft_lstnew_subnode(char *content);
t_subnode	*ft_lstlast_subnode(t_subnode *lst);
void		ft_lstadd_back_subnode(t_subnode **lst, t_subnode *new);
//list environment functions
void	cpy_env(t_env **ptr, const char **envp);
void 	ft_freeenv(t_env **lst);
t_env   *new_node_env(const char *line_env);
void	ft_addback_node_env(t_env **lst, t_env *new);
//redir func
void	handleOutFileRedirection(t_var *var);
void	handleInFileRedirection(t_var *var);
void    base_redir(t_var *var);
//moha
int		cd(t_node *tokens);
void	echo(t_node *tokens);
void 	run_builtin(t_var *var);
int		pwd(t_var	*var);
int		env(t_var *var);
int 	export(t_var *var);
void	unset(t_var *var);
#endif