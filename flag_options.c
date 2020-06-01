/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/04/29 22:58:33 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_options(char *f, char specifier)
{
	int		flags;
	int		c_null;

	flags = 0;
	c_null = 0;
	while (*f == '+' || *f == '-' || *f == '#' || *f == '0' || *f == ' ')
	{
		(*f == '+') ? flags = flags | 1 : flags;
		(*f == '-') ? flags = flags | 2 : flags;
		(*f == '#') ? flags = flags | 4 : flags;
		(*f == '0') ? flags = flags | 8 : flags;
		(*f == ' ') ? flags = flags | 16 : flags;
		f++;
	}
	fix_incompatible_flags(&flags);
	solve_plus_flag_with_types(&flags, specifier);
	solve_minusflag_with_types(&flags, specifier);
	solve_hash_flag_with_types(&flags, specifier);
	solve_zero_flag_with_types(&flags, specifier);
	solve_spaceflag_with_types(&flags, specifier);
	big_hub(&flags, &c_null, &c_null, &c_null);
	return (f);
}

void	fix_incompatible_flags(int *flags)
{
	int temp;
	temp = *flags;
	temp = (temp | 23) ^ 23;
	if (temp == 8)
		*flags = *flags ^ 8;
	else
	{
		temp = *flags;
		temp = (temp | 15) ^ 15;
		if (temp == 16)
			*flags = *flags ^ 16;
	}

