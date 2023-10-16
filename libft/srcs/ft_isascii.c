/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 08:53:36 by mfornah           #+#    #+#             */
/*   Updated: 2022/09/21 09:36:06 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isascii(int str)
{
	if (str >= 0 && str <= 127)
		return (1);
	else
		return (0);
}
/*
int main(void)
{
    int str;

    str = "ª";

    ft_isascii(str);
    printf("%d",ft_isascii(str));
}*/