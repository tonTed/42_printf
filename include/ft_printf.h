/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:27:13 by tblanco           #+#    #+#             */
/*   Updated: 2021/11/07 16:40:09 by tblanco          ###   ########.fr       */
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

/* libft */
size_t	ft_strlen(char *s);
int     ft_putstr(char *s);
int		ft_putchar(char c);
/* printf */
int	ft_printf(const char *format, ...);

#include <stdio.h>
#endif
