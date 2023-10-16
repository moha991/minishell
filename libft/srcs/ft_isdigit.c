/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:18:14 by mfornah           #+#    #+#             */
/*   Updated: 2023/07/10 02:05:52 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isdigit(char str)
{
	while (str == '+' || str == '-')
		str++;
	if (str >= '0' && str <= '9')
		return (1);
	return (0);
}
/*
int	main(void)
{
	int	str;

	str = 'a';

	ft_isdigit(str);

	printf("%d",ft_isdigit(str));

}
*/