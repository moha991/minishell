/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:17:19 by smagniny          #+#    #+#             */
/*   Updated: 2023/11/19 22:49:44 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	is_space_or_eof(int c)
{
	return ((c == ' ' || c == '\0') || c == '\t');
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
