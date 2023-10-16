/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:48:19 by mfornah           #+#    #+#             */
/*   Updated: 2022/12/01 15:45:00 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

# define DECIMAL "0123456789"
# define HEXADECIMAL_MA "0123456789ABCDEF"
# define HEXADECIMAL_MIN "0123456789abcdef"

int				ft_printf(char const *format, ...);
int				ft_print_putchar(char c);
int				ft_print_putstr(const char *str);
int				ft_printf_ptr(void *ptr);
int				ft_printf_hexlong(unsigned long nbr, char *base);
int				ft_checkparam(const char *input, int i, int count, va_list pa);

int				ft_print_unsingened(unsigned int num);
int				ft_printf_putnbr(int n);
size_t			ft_strlen2(const char *str);
int				ft_putnbr_base_uns(unsigned int nbr, char *base);
int				ft_print_pa(int i, int count, const char *inp, va_list argms);
int				ft_hexpointer(unsigned long pnt);
int				ft_checkbase(char *base);

#endif