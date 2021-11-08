/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:38:56 by tblanco           #+#    #+#             */
/*   Updated: 2021/11/07 19:26:29 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_lennb_base(unsigned long long nb, int lenbase)
{
	int	len;

	len = 1;
	while (nb >= (unsigned long long) lenbase)
	{
		nb = nb / lenbase;
		len++;
	}
	return (len);
}

int	ft_puthex(unsigned long long nb, char conv, char *base)
{
	int		len;
	int		len_base;
	char	*to_print;

	len_base = ft_strlen(base);
	len = ft_lennb_base(nb, len_base);
	to_print = (char *)malloc(sizeof(char) * (len + 1));
	if (!to_print)
		return (0);
	if (conv == 'X')
		base = HEX_UPPER;
	to_print[len] = 0;
	while (len--)
	{
		to_print[len] = base[nb % len_base];
		nb /= len_base;
	}
	len = ft_putstr(to_print);
	free(to_print);
	return (len);
}

int	ft_putnbr(int nb, char conv)
{
	unsigned long long n;
	int len;

	len = 0;
	if (nb < 0)
	{
		n =(unsigned long long)nb * -1;
		len += ft_putchar('-');
	}
	else
		n = nb;
	len += ft_puthex(n, conv, DECIMAL);
	return (len);
}