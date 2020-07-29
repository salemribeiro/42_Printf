/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/07/28 20:44:29 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_options(char *f, char specifier)
{
	int		flags;

	flags = 0;
	while (*f == '+' || *f == '-' || *f == '#' || *f == '0' || *f == ' ')
	{
		(*f == '+') ? flags = flags | PLUS : flags;
		(*f == '-') ? flags = flags | MINUS : flags;
		(*f == '#') ? flags = flags | HASH : flags;
		(*f == '0') ? flags = flags | ZERO : flags;
		(*f == ' ') ? flags = flags | SPACE : flags;
		f++;
	}
	solve_incompatible(&flags);
	solve_plus(&flags, specifier);
	solve_minus(&flags, specifier);
	solve_hash(&flags, specifier);
	solve_zero(&flags, specifier);
	solve_space(&flags, specifier);
	parameters.flags = flags;
	return (f);
}

void	solve_incompatible(int *flags)
{
	if ((*flags & PLUS) == PLUS && (*flags & SPACE) == SPACE)
		*flags = *flags ^ SPACE;
	if ((*flags & MINUS) == MINUS && (*flags & ZERO) == ZERO)
		*flags = *flags ^ ZERO;
}
