/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:43:56 by tblanco           #+#    #+#             */
/*   Updated: 2021/11/07 19:43:43 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (!s || !s[len])
		return (len);
	while (s[len])
		len++;
	return (len);
}

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
