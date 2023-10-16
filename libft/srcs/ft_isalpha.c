/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:18:14 by mfornah           #+#    #+#             */
/*   Updated: 2022/09/21 09:24:06 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isalpha(int str)
{
	if ((str >= 'A' && str <= 'Z' ) || (str >= 'a' && str <= 'z'))
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	int	str;

	str = '2';

	ft_isalpha(str);

	printf("%d",ft_isalpha(str));

}
*/