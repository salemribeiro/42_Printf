/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_and_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/06/29 22:39:23 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	solve_plus(int *flags, char specifier)
{
	int		i;
	int		valid;
	int		tmp;

	i = 0;
	valid = 0;
	tmp = *flags & PLUS;
	while (FORBIDEN1[i])
	{
		if (FORBIDEN1[i] == specifier)
			valid = 1;
		i++;
	}
	if (tmp == PLUS && valid == 1)
		*flags = *flags ^ PLUS;
}

void	solve_minus(int *flags, char specifier)
{
	int tmp;

	tmp = *flags & MINUS;
	if (tmp == MINUS && specifier == 'n')
		*flags = *flags ^ MINUS;
}

void	solve_hash(int *flags, char specifier)
{
	int		i;
	char	valid;
	int		tmp;

	i = 0;
	valid = 0;
	tmp = *flags & HASH;
	while (FORBIDEN2[i])
	{
		if (FORBIDEN2[i] == specifier)
			valid = 1;
		i++;
	}
	if (tmp == HASH && valid == 1)
		*flags = *flags ^ HASH;
}

void	solve_zero(int *flags, char specifier)
{
	int		i;
	char	valid;
	int		tmp;

	i = 0;
	valid = 0;
	tmp = *flags & ZERO;
	while (FORBIDEN3[i])
	{
		if (FORBIDEN3[i] == specifier)
			valid = 1;
		i++;
	}
	if (tmp == ZERO && valid == 1)
		*flags = *flags ^ ZERO;
}

void	solve_space(int *flags, char specifier)
{
	int		i;
	char	valid;
	int		tmp;

	i = 0;
	valid = 0;
	tmp = *flags & SPACE;
	while (FORBIDEN1[i])
	{
		if (FORBIDEN1[i] == specifier)
			valid = 1;
		i++;
	}
	if (tmp == SPACE && valid == 1)
		*flags = *flags & SPACE;
}
