/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_options_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 22:19:47 by salem             #+#    #+#             */
/*   Updated: 2020/11/30 22:23:30 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
**  Recebe um conjunto de caracters em um ponteiro de char "*parameters",
** percorre todo ponteiro em busca de valores que representam flags, envia
** essas flags para o campo da estrutura global "g_opt.flags" e avanca o
** ponteiro para posicao final de indicacao de flags e retorna o mesmo.
*/

char	*flag_options(char *parameters, char specifier)
{
	char	flags;

	flags = 0;
	while (*parameters == '+' || *parameters == '-' || *parameters == '#' ||
			*parameters == '0' || *parameters == ' ')
	{
		flags = (*parameters == '+') ? flags | PLUS : flags;
		flags = (*parameters == '-') ? flags | MINUS : flags;
		flags = (*parameters == '#') ? flags | HASH : flags;
		flags = (*parameters == '0') ? flags | ZERO : flags;
		flags = (*parameters == ' ') ? flags | SPACE : flags;
		parameters++;
	}
	g_opt.flags = solve_incompatible(flags, specifier);
	return (parameters);
}

/*
**  Recebe um inteiro char "flags" e executa uma série de verificacoes
** corrigindo suas incompatibilidades por ordem de importancia, retornando um
** inteiro char com as correcoes aplicadas.
**  Foi desenhado dessa forma para que os tratamentos poderem ser chamados em
** qualquer parte do codigo
*/

char	solve_incompatible(char flags, char specifier)
{
	if ((flags & PLUS) == PLUS && (flags & SPACE) == SPACE)
		flags = flags ^ SPACE;
	if ((flags & MINUS) == MINUS && (flags & ZERO) == ZERO)
		flags = flags ^ ZERO;
	flags = solve_plus(flags, specifier);
	flags = solve_minus(flags, specifier);
	flags = solve_hash(flags, specifier);
	flags = solve_zero(flags, specifier);
	flags = solve_space(flags, specifier);
	return (flags);
}
