/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/06/29 22:18:50 by salem            ###   ########.fr       */
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
	big_hub(flags, 1);
	return (f);
}

void	solve_incompatible(int *flags)
{
	int tmp;

	tmp = *flags;
	tmp = tmp & ZERO ;
	if (tmp == ZERO)
		*flags = *flags ^ ZERO;
	else
	{
		tmp = *flags;
		tmp = tmp & SPACE;
		if (tmp == SPACE)
			*flags = *flags ^ SPACE;
	}
}
