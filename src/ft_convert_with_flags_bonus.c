/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_with_flags_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:13:14 by tblanco           #+#    #+#             */
/*   Updated: 2021/11/11 22:50:14 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

//			-	+	#	0	 	w	.
//		c	x					x
int ft_convert_char(t_flags flags, va_list *args)
{
	char	c;
	size_t  len;
	size_t	printed;
	
	if (flags.width > 1)
		len = flags.width;
	else
		return (ft_putchar(va_arg(*args, unsigned int)));
	printed = 0;
	if (flags.opts & OPT_NEG)
	{
		ft_putchar(va_arg(*args, unsigned int));
		while (++printed < len)
			ft_putchar(' ');
		return (len);
	}
	if (flags.opts & OPT_0)
		c = '0';
	else
		c = ' ';
	while (printed++ < (len - 1))
		ft_putchar(c);
	ft_putchar(va_arg(*args, unsigned int));
	return (len);
}