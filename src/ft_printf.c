/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:30:08 by tblanco           #+#    #+#             */
/*   Updated: 2021/11/07 16:48:11 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
#include "ft_printf.h"

/*
	%c imprime un seul caractère.
		L'argument entier, de type int, est converti en un unsigned char, et le
		caractère correspondant est affiché.

	%s imprime une chaîne de caractères.
		L'argument de type const char * est supposé être un pointeur sur un
		tableau de caractères (pointeur sur une chaîne). Les caractères du
		tableau sont écrits jusqu'à l'octet nul « \0 » final, non compris. Si
		une précision est indiquée, seul ce nombre de caractères sont écrits.
		Si une précision est fournie, il n'y a pas besoin d'octet nul. Si la
		précision n'est pas donnée, ou si elle est supérieure à la longueur de
		la chaîne, l'octet nul final est nécessaire. 

	%p L’argument de pointeur void * est imprimé en hexadécimal.
		L'argument pointeur, du type void * est affiché en hexadécimal, comme
		avec %#x ou %#lx.

	%d imprime un nombre décimal (base 10).
	%i imprime un entier en base 10.
		L'argument int est converti en un chiffre décimal signé. La précision,
		si elle est mentionnée, correspond au nombre minimal de chiffres qui
		doivent apparaître. Si la conversion fournit moins de chiffres, le
		résultat est rempli à gauche avec des zéros. Par défaut la précision
		vaut 1. Lorsque 0 est converti avec une précision valant 0, la sortie
		est vide. 

	%u imprime un nombre décimal non signé (base 10).
	%x imprime un nombre en hexadécimal (base 16) abcdef.
	%X imprime un nombre en hexadécimal (base 16) ABCDEF.
		La précision, si elle est indiquée, donne un nombre minimal de chiffres
		à faire apparaître. Si la valeur convertie nécessite moins de chiffres,
		elle est complétée à gauche avec des zéros. La précision par défaut vaut
		1. Lorsque 0 est converti avec une précision valant 0, la sortie est
		vide. 
	%% imprime un signe de pourcentage.

	BONUS:
	Le caractère % peut être éventuellement suivi par un ou plusieurs attributs
	suivants :

	- : indique que la valeur doit être justifiée sur la limite gauche du champ
	(par défaut elle l'est à droite). Les valeurs sont complétées à droite par
	des espaces, plutôt qu'à gauche par des zéros ou des blancs. Un attribut -
	surcharge un attribut 0 si les deux sont fournis. 

	0 : indique le remplissage avec des zéros. 
	Pour les conversions d, i, u, x, X, la valeur est complétée à gauche avec
	des zéros plutôt qu'avec des espaces. Si les attributs 0 et - apparaissent
	ensemble, l'attribut 0 est ignoré. Si une précision est fournie avec une
	conversion numérique (d, i, u, x, et X), l'attribut 0 est ignoré.
	Pour les autres conversions, le comportement est indéfini.

	. : Une précision éventuelle, sous la forme d'un point (« . ») suivi par
	un nombre. À la place de la chaîne représentant le nombre décimal, on peut
	écrire « * » ou « *m$ » (m étant entier) pour indiquer que la précision est
	fournie dans l'argument suivant, ou dans le m-ième argument,
	respectivement. L'argument fournissant la précision doit être de type int.
	Si la précision ne contient que le caractère « . », ou une valeur négative,
	elle est considérée comme nulle. Cette précision indique un nombre minimum
	de chiffres à faire apparaître lors des conversions d, i, u, x, et X, le
	nombre maximum de caractères à imprimer depuis une chaîne pour les
	conversions s. 

	widht: Un nombre optionnel ne commençant pas par un zéro, peut indiquer une
	largeur minimale de champ. Si la valeur convertie occupe moins de
	caractères que cette largeur, elle sera complétée par des espaces à gauche
	(ou à droite si l'attribut d'alignement à gauche a été fourni). À la place
	de la chaîne représentant le nombre décimal, on peut écrire « * » ou
	« *m$ » (m étant entier) pour indiquer que la largeur du champ est fournie
	dans l'argument suivant, ou dans le m-ième argument, respectivement.
	L'argument fournissant la largeur doit être de type int. Une largeur
	négative est considéré comme l'attribut « - » vu plus haut suivi d'une
	largeur positive. En aucun cas une largeur trop petite ne provoque la
	troncature du champ. Si le résultat de la conversion est plus grand que la
	largeur indiquée, le champ est élargi pour contenir le résultat.   

	# : Pour les conversions x et X une valeur non nulle reçoit le préfixe
	« 0x » (ou « 0X » pour l'indicateur X). Pour les autres conversions, cet
	attribut n'a pas d'effet.

	  : (une espace) indique qu'une espace doit être laissée avant un nombre
	  positif (ou une chaîne vide) produit par une conversion signée

	+ : Un signe (+ ou -) doit toujours être imprimé avant un nombre produit
	par une conversion signée. Par défaut, un signe n'est utilisé que pour des
	valeurs négatives. Un attribut + surcharge un attribut « espace » si les
	deux sont fournis. 
*/

int		ft_manage_conv(char conv, va_list *args)
{
	int	len;
	
	len = 0;
	if (conv == 's')
		len = ft_putstr(va_arg(*args, char*));
	else if (conv == 'c')
		len = ft_putchar(va_arg(*args, unsigned int));
	else if (conv == '%')
		len = ft_putchar('%');
	
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list args;
	int		len;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			len++;
		}
		else
			len += ft_manage_conv(*(++format), &args);
		format++;
	}	
	return len;
}