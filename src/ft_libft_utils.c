/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:43:56 by tblanco           #+#    #+#             */
/*   Updated: 2021/11/07 16:39:56 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
// #include "printf.h"

size_t	ft_strlen(char *s)
{
	size_t len;
	
	len = 0;
	if (!s || !s[len])
		return (len);
	while (s[len])
		len++;
	return (len);
}

int		ft_putstr(char *s)
{
	int len;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = (int)ft_strlen(s);
	write(1, s, len);
	return ((int) len);
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}