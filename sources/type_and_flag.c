/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_and_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/08/13 23:43:46 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  Recebe como parametro o inteiro do tipo char "flags", verifica se a flag
** pode ser utilizada com lista de especificadores "SPECIFIERS1" e retorna o
** inteiro do tipo char "flags" com seus bits tratados.
*/

char	solve_plus(char flags)
{
	int		i;
	int		valid;
	int		tmp;

	i = 0;
	valid = 0;
	tmp = flags & PLUS;
	while (SPECIFIERS1[i])
	{
		if (SPECIFIERS1[i] == g_opt.specifier)
			valid = 1;
		i++;
	}
	if (tmp == PLUS && valid == 1)
		flags = flags ^ PLUS;
	return (flags);
}

/*
**  Recebe como parametro o inteiro do tipo char "flags", verifica se a flag
** pode ser utilizada com o especificador "n" e retorna o inteiro do tipo char 
** "flags" com seus bits tratados.
*/

char	solve_minus(char flags)
{
	int tmp;

	tmp = flags & MINUS;
	if (tmp == MINUS && g_opt.specifier == 'n')
		flags = flags ^ MINUS;
	return (flags);
}

/*
**  Recebe como parametro o inteiro do tipo char "flags", verifica se a flag
** pode ser utilizada com lista de especificadores "SPECIFIERS2" e retorna o
** inteiro do tipo char "flags" com seus bits tratados.
*/

char	solve_hash(char flags)
{
	int		i;
	char	valid;
	int		tmp;

	i = 0;
	valid = 0;
	tmp = flags & HASH;
	while (SPECIFIERS2[i])
	{
		if (SPECIFIERS2[i] == g_opt.specifier)
			valid = 1;
		i++;
	}
	if (tmp == HASH && valid == 1)
		flags = flags ^ HASH;
	return (flags);
}

/*
**  Recebe como parametro o inteiro do tipo char "flags", verifica se a flag
** pode ser utilizada com lista de especificadores "SPECIFIERS3" e retorna o
** inteiro do tipo char "flags" com seus bits tratados.
*/

char	solve_zero(char flags)
{
	int		i;
	char	valid;
	int		tmp;

	i = 0;
	valid = 0;
	tmp = flags & ZERO;
	while (SPECIFIER3[i])
	{
		if (SPECIFIER3[i] == g_opt.specifier)
			valid = 1;
		i++;
	}
	if (tmp == ZERO && valid == 1)
		flags = flags ^ ZERO;
	return (flags);
}

/*
**  Recebe como parametro o inteiro do tipo char "flags", verifica se a flag
** pode ser utilizada com lista de especificadores "SPECIFIERS1" e retorna o
** inteiro do tipo char "flags" com seus bits tratados.
*/

char	solve_space(char flags)
{
	int		i;
	char	valid;
	int		tmp;

	i = 0;
	valid = 0;
	tmp = flags & SPACE;
	while (SPECIFIERS1[i])
	{
		if (SPECIFIERS1[i] == g_opt.specifier)
			valid = 1;
		i++;
	}
	if (tmp == SPACE && valid == 1)
		flags = flags ^ SPACE;
	return (flags);
}
