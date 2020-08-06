/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/08/05 00:04:15 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_options(char *f)
{
	int		flags;

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
	parameters.flags = flags;
	solve_incompatible();
	return (f);
}

void	solve_incompatible()
{
	if ((parameters.flags & PLUS) == PLUS &&
	(parameters.flags & SPACE) == SPACE)
		parameters.flags = parameters.flags ^ SPACE;
	if ((parameters.flags & MINUS) == MINUS &&
	(parameters.flags & ZERO) == ZERO)
		parameters.flags = parameters.flags ^ ZERO;
	solve_plus();
	solve_minus();
	solve_hash();
	solve_zero();
	solve_space();
}
