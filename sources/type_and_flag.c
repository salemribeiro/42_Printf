/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_and_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/08/04 22:08:45 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	solve_plus()
{
	int		i;
	int		valid;
	int		tmp;

	i = 0;
	valid = 0;
	tmp = parameters.flags & PLUS;
	while (FORBIDEN1[i])
	{
		if (FORBIDEN1[i] == parameters.specifier)
			valid = 1;
		i++;
	}
	if (tmp == PLUS && valid == 1)
		parameters.flags = parameters.flags ^ PLUS;
}

void	solve_minus()
{
	int tmp;

	tmp = parameters.flags & MINUS;
	if (tmp == MINUS && parameters.specifier == 'n')
		parameters.flags = parameters.flags ^ MINUS;
}

void	solve_hash()
{
	int		i;
	char	valid;
	int		tmp;

	i = 0;
	valid = 0;
	tmp = parameters.flags & HASH;
	while (FORBIDEN2[i])
	{
		if (FORBIDEN2[i] == parameters.specifier)
			valid = 1;
		i++;
	}
	if (tmp == HASH && valid == 1)
		parameters.flags = parameters.flags ^ HASH;
}

void	solve_zero()
{
	int		i;
	char	valid;
	int		tmp;

	i = 0;
	valid = 0;
	tmp = parameters.flags & ZERO;
	while (FORBIDEN3[i])
	{
		if (FORBIDEN3[i] == parameters.specifier)
			valid = 1;
		i++;
	}
	if (tmp == ZERO && valid == 1)
		parameters.flags = parameters.flags ^ ZERO;
}

void	solve_space()
{
	int		i;
	char	valid;
	int		tmp;

	i = 0;
	valid = 0;
	tmp = parameters.flags & SPACE;
	while (FORBIDEN1[i])
	{
		if (FORBIDEN1[i] == parameters.specifier)
			valid = 1;
		i++;
	}
	if (tmp == SPACE && valid == 1)
		parameters.flags = parameters.flags ^ SPACE;
}
