/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohafnh <mohafnh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:27:51 by mfornah           #+#    #+#             */
/*   Updated: 2023/10/15 12:39:23 by mohafnh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <strings.h>
# include <string.h>
# include <unistd.h>
# include <ctype.h>
# include <stddef.h>
# include <stdio.h>
# include "fcntl.h"

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

int		ft_isalpha(int str);
int		ft_isdigit(int str);
int		ft_isalnum(int str);
int		ft_isprint(int str);
int		ft_isascii(int str);

size_t	ft_strlen(char *str);
void	*ft_memset(void *dest, int ch, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *str1, const void *str2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst,  char *src, size_t dstsize);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, unsigned int nb);

int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(char *s, int c);
char	*ft_strrchr( char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_putstr_fd(char *s, int fd);

void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *str);

void	ft_putstr(char *str);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_strdup(char *src);
void	ft_putendl_fd(char *s, int fd);

char	*ft_substr(char  *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char  *s2);
char	*ft_strtrim(char  *s1, char  *set);
char	*ft_itoa(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);

char	*ft_strmapi(char  *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	**ft_split(char  *s, char c);

void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int		ft_printf(char const *format, ...);
char	*get_next_line(int fd);

#endif