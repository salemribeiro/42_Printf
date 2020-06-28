/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/06/28 20:41:27 by salem            ###   ########.fr       */
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
	fix_incompatible_flags(&flags);
	solve_plus_flag_with_types(&flags, specifier);
	solve_minusflag_with_types(&flags, specifier);
	solve_hash_flag_with_types(&flags, specifier);
	solve_zero_flag_with_types(&flags, specifier);
	solve_spaceflag_with_types(&flags, specifier);
	big_hub(flags, 1);
	return (f);
}

void	fix_incompatible_flags(int *flags)
{
	int tmp;
	tmp = *flags;
	tmp = tmp & ZERO ;
	if (tmp == 8)
		*flags = *flags ^ 8;
	else
	{
		tmp = *flags;
		tmp = tmp & SPACE;
		if (tmp == 16)
			*flags = *flags ^ 16;
	}
}
