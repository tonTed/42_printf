/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:27:13 by tblanco           #+#    #+#             */
/*   Updated: 2021/11/07 19:45:36 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* includes */
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/* define */
# define CONV "cspdiuxX%"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# define DECIMAL "0123456789"

/* utils */
size_t	ft_strlen(char *s);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putnbr(int nb, char conv);
int		ft_putbase(unsigned long long nb, char conv, char *base);

/* printf */
int		ft_printf(const char *format, ...);

#endif
