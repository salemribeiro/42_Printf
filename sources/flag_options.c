/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/08/14 09:23:50 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  Recebe um conjunto de caracters em um ponteiro de char "*parameters",
** percorre todo ponteiro em busca de valores que representam flags, envia
** essas flags para o campo da estrutura global "g_opt.flags" e avanca o
** ponteiro para posicao final de indicacao de flags e retorna o mesmo.
*/

char	*flag_options(char *parameters)
{
	char	flags;

	flags = 0;
	while (*f == '+' || *f == '-' || *f == '#' || *f == '0' || *f == ' ')
	{
		flags = (*f == '+') ? flags | PLUS : flags;
		flags = (*f == '-') ? flags | MINUS : flags;
		flags = (*f == '#') ? flags | HASH : flags;
		flags = (*f == '0') ? flags | ZERO : flags;
		flags = (*f == ' ') ? flags | SPACE : flags;
		f++;
	}
	g_opt.flags = solve_incompatible(flags);
	return (f);
}

/*
**  Recebe um inteiro char "flags" e executa uma série de verificacoes
** corrigindo suas incompatibilidades por ordem de importancia, retornando um
** inteiro char com as correcoes aplicadas.
**  Foi desenhado dessa forma para os tratamentos poderem ser chamados em
** qualquer parte do código
*/

char	solve_incompatible(char flags)
{
	if ((flags & PLUS) == PLUS && (flags & SPACE) == SPACE)
		flags = flags ^ SPACE;
	if ((flags & MINUS) == MINUS && (flags & ZERO) == ZERO)
		flags = flags ^ ZERO;
	flags = solve_plus(flags);
	flags = solve_minus(flags);
	flags = solve_hash(flags);
	flags = solve_zero(flags);
	flags = solve_space(flags);
	return (flags);
}
