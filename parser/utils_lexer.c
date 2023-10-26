/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:17:19 by smagniny          #+#    #+#             */
/*   Updated: 2023/10/26 19:42:29 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	is_space_or_eof(int c)
{
	return (c == ' ' || c == '\0');
}

int	isdoublequote(int c)
{
	return (c == '\"');
}

int	issinglequote(int c)
{
	return (c == '\'');
}

int	isingle_operator(char *line, int i)
{
	return (line[i] == '|' || (line[i] == '>' && line[(i + 1)] != '>')
		|| (line[i] == '<' && line[(i + 1)] != '<'));
}

int	isdouble_operator(char *line, int i)
{
	return ((line[i] == '>' && line[(i + 1)] == '>')
		|| (line[i] == '<' && line[(i + 1)] == '<'));
}
