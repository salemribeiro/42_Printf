/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_and_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/04/29 22:58:33 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	solve_plus_flag_with_types(char *flags, char specifier)
{
	char forbiden[9];
	char temp;
	char valid;
	int i;

	ft_strlcpy(forbiden, "uoxXcspn", 9);
	temp = (*flags | 30) ^ 30;
	valid = 0;
	i = 0;
	while (forbiden[i])
	{
		if (forbiden[i] == specifier)
			valid = 1;
		i++;
	}
	if (temp == 1 && valid == 1)
		*flags = *flags ^ 1;
}

void	solve_minusflag_with_types(char *flags, char specifier)
{
	char temp;
	int i;

	temp = (*flags | 29)  ^ 29;
	if (temp == 2 && specifier == 'n')
		*flags = *flags ^ 2;
}

void	solve_hash_flag_with_types(char *flags, char specifier)
{
	char forbiden[8];
	char temp;
	char valid;
	int i;

	ft_strlcpy(forbiden, "diucspn", 8);
	temp = (*flags | 27) ^ 27;
	valid = 0;
	i = 0;
	while (forbiden[i])
	{
		if (forbiden[i] == specifier)
			valid = 1;
		i++;
	}
	if (temp == 4 && valid == 1)
		*flags = *flags ^ 4;
}

void	solve_zero_flag_with_types(char *flags, char specifier)
{
	char forbiden[5];
	char temp;
	char valid;
	int i;

	ft_strlcpy(forbiden, "cspn", 5);
	temp = (*flags | 23) ^ 23;
	valid = 0;
	i = 0;
	while (forbiden[i])
	{
		if (forbiden[i] == specifier)
			valid = 1;
		i++;
	}
	if (temp == 8 && valid == 1)
		*flags = *flags ^ 8;
}

void	solve_spaceflag_with_types(char *flags, char specifier)
{
	char forbiden[9];
	char temp;
	char valid;
	int i;

	ft_strlcpy(forbiden, "uoxXcspn", 9);
	temp = (*flags | 15) ^ 15;
	valid = 0;
	i = 0;
	while (forbiden[i])
	{
		if (forbiden[i] == specifier)
			valid = 1;
		i++;
	}
	if (temp == 16 && valid == 1)
		*flags = *flags ^ 16;
}
