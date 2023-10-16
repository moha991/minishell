/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:28:01 by mfornah           #+#    #+#             */
/*   Updated: 2023/03/09 11:22:03 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * It takes a string, finds the first newline character,
 *  and returns a new string that contains
 * everything after the newline
 * 
 * @param stash the string that contains the leftover c
 * haracters from the previous read
 * 
 * @return A pointer to a string.
 */
char	*ft_save(char *stash)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		str[j++] = stash[i++];
	str[j] = '\0';
	free(stash);
	return (str);
}

/**
 * It returns a string containing the first line of the string passed to it
 * 
 * @param stash the string that contains the line
 * 
 * @return A pointer to a string.
 */
char	*ft_line(char *stash)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash [i] != '\n' )
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (stash[i] && stash [i] != '\n')
	{
		str[i] = stash [i];
		i++;
	}
	if (stash [i] == '\n')
	{
		str[i] = stash [i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/**
 * It reads from a file descriptor and stores the read data in a string
 * 
 * @param fd file descriptor
 * @param stash the string that holds the data read from the file descriptor.
 * 
 * @return A pointer to a string.
 */
char	*ft_read_and_stash(int fd, char *stash)
{
	char	*bufer;
	int		readed;

	bufer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!bufer)
		return (NULL);
	readed = 1;
	while (!ft_strchr(stash, '\n') && readed != '\0')
	{
		readed = read(fd, bufer, BUFFER_SIZE);
		if (readed < 0)
		{
			free(bufer);
			return (NULL);
		}
		bufer [readed] = '\0';
		stash = ft_strjoin(stash, bufer);
	}
	free(bufer);
	return (stash);
}

/**
 * Read from the file descriptor and store 
 * the read data in a static variable. If the static variable
 * contains a newline, return the data up to the newline.
 *  If the static variable does not contain a
 * newline, read from the file descriptor again and 
 * append the read data to the static variable. If the
 * file descriptor has no more data to read, 
 * return the data in the static variable
 * 
 * @param fd the file descriptor from which to read
 * 
 * @return A line of text from the file descriptor.
 */
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (stash);
		stash = NULL;
		return (stash);
	}
	stash = ft_read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_line(stash);
	stash = ft_save(stash);
	return (line);
}
