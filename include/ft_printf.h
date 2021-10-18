/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:27:13 by tblanco           #+#    #+#             */
/*   Updated: 2021/10/18 18:04:57 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* includes */
# include <stdarg.h>
# include <unistd.h>

/* define */
# define CONV "cspdiuxX%"
# define HEX_MINUS "0123456789abcdef"
# define DECIMAL "0123456789"

/* libft */
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putbase(int n, int *printed, char *base);

/* printf */
int	ft_printf(const char *format, ...);

#include <stdio.h>
#endif
