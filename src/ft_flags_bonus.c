/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 21:05:33 by tblanco           #+#    #+#             */
/*   Updated: 2021/11/11 22:50:16 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/ft_printf_bonus.h"
#include "../test/ft_colors.h"

/*

	OPTS | width | . |

> -: justification gauche (espace droite)
*/

int		ft_getopts(const char **s)
{
	int opts;

	opts = 0;
	while (*(*s))
	{
		if (*(*s) == '-')
			opts |= OPT_NEG;
		else if (*(*s) == '+')
			opts |= OPT_POS;
		else if (*(*s) == '#')
			opts |= OPT_H;
		else if (*(*s) == '0')
			opts |= OPT_0;
		else if (*(*s) == ' ')
			opts |= OPT_SP;
		else
			break ;
		(*s)++;
	}
	if (opts & OPT_NEG && opts & OPT_0)
		opts ^= OPT_0;
	if (opts & OPT_POS && opts & OPT_SP)
		opts ^= OPT_SP;
	return (opts);
}

int		ft_getnumber(const char **s)
{
	int nb;

	nb = 0;
	while (ft_isnum(*(*s)))
	{
		nb = (nb * 10) + (*(*s) - '0');
		(*s)++;
	}
	return (nb);
}

t_flags	ft_getflags(const char **s)
{
	t_flags	flags;

	flags.opts = ft_getopts(s);
	flags.width = ft_getnumber(s);
	if (*(*s) == '.')
		flags.prec = ft_getnumber(++s);
	else
		flags.prec = 0;
	return (flags);
}



int	ft_manage_flags(const char **format, va_list *args)
{
	t_flags flags;

	flags = ft_getflags(format);
	// check conversions & masquing options
	if (*(*format) == 'c')
		return (ft_convert_char(flags, args));
	return 0;
}

