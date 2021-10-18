/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:43:56 by tblanco           #+#    #+#             */
/*   Updated: 2021/10/18 18:05:00 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
// #include "printf.h"

int ft_strlen(char *s)
{
	int ret;

	ret = 0;
	while(*s++)
		ret++;
	return (ret);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *s)
{
	int len;

	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

int	ft_putbase(int n, int *printed, char *base)
{
	long	nb_long;
	int		len_base;

	len_base = ft_strlen(base);
	nb_long = n;
	if (nb_long < 0)
	{
		*printed += ft_putchar('-');
		nb_long = -nb_long;
	}
	if (nb_long >= len_base)
	{
		ft_putbase(nb_long / len_base, printed, base);
		ft_putbase(nb_long % len_base, printed, base);
	}
	else
		*printed += ft_putchar(base[nb_long]);
	return (*printed);
}