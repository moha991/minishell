/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:54:37 by mfornah           #+#    #+#             */
/*   Updated: 2022/09/21 09:56:04 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isprint(int str)
{
	if (str >= 32 && str < 127)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	int	str;

	str = 128;

	ft_isprint(str);

	printf("%d",ft_isprint(str));

}*/