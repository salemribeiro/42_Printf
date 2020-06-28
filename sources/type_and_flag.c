/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_and_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/06/28 00:05:57 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define FORBIDEN1 "uoxXcspn\0"
#define FORBIDEN2 "diucspn\0"
#define FORBIDEN3 "cdpn\0"

void	solve_plus_flag_with_types(int *flags, char specifier)
{
	int		i;
	int		tmp;
	int		valid;

	i = 0;
	valid = 0;
	tmp = (*flags | 30) ^ 30;
	while (FORBIDEN1[i])
	{
		if (FORBIDEN1[i] == specifier)
			valid = 1;
		i++;
	}
	if (tmp == 1 && valid == 1)
		*flags = *flags ^ 1;
}

void	solve_minusflag_with_types(int *flags, char specifier)
{
	int tmp;
	int i;

	tmp = (*flags | 29)  ^ 29;
	if (tmp == 2 && specifier == 'n')
		*flags = *flags ^ 2;
}

void	solve_hash_flag_with_types(int *flags, char specifier)
{
	int		i;
	int		tmp;
	char	valid;

	i = 0;
	valid = 0;
	tmp = (*flags | 27) ^ 27;
	while (FORBIDEN2[i])
	{
		if (FORBIDEN2[i] == specifier)
			valid = 1;
		i++;
	}
	if (tmp == 4 && valid == 1)
		*flags = *flags ^ 4;
}

void	solve_zero_flag_with_types(int *flags, char specifier)
{
	int		i;
	int		tmp;
	char	valid;

	tmp = (*flags | 23) ^ 23;
	valid = 0;
	i = 0;
	while (FORBIDEN3[i])
	{
		if (FORBIDEN3[i] == specifier)
			valid = 1;
		i++;
	}
	if (tmp == 8 && valid == 1)
		*flags = *flags ^ 8;
}

void	solve_spaceflag_with_types(int *flags, char specifier)
{
	int		i;
	int		tmp;
	char	valid;

	tmp = (*flags | 15) ^ 15;
	valid = 0;
	i = 0;
	while (FORBIDEN1[i])
	{
		if (FORBIDEN1[i] == specifier)
			valid = 1;
		i++;
	}
	if (tmp == 16 && valid == 1)
		*flags = *flags ^ 16;
}
