/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 19:26:26 by sfreitas          #+#    #+#             */
/*   Updated: 2020/09/07 20:32:28 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

char	round_number(char *value, int precision)
{
	int i;
	int flags;

	i = precision - 1;
	flags = 0;
	while (i >= 0 && value[i] >= 5)
	{
		if (value[i] >= 5 && i > 0)
		{
			if (value[i - 1] < 9)
				value[i - 1]++;
			else if (value[i] == 9)
				value[i - 1] = 0;
		}
		else if (value[i] >= 5 && i == 0)
			flags = 1;
		i--;
	}
	return (flags);
}

char	*convert_char(long double value, int precision)
{
	long long int	v_int;
	long double	v_doub;
	char			*c_number;
	int				i;

	v_int = 0;
	v_doub = 0;
	i = 0;
	v_int = (long long int)value;
	value = value < 0 ? value * (-1) : value;
	v_doub = value - (long double)(long long int)value;
	c_number = ft_calloc(precision + 1, sizeof(char));
	while (i < precision)
	{
		v_doub = v_doub * 10;
		c_number[i] = (char)v_doub;
		v_doub = v_doub - (long double)c_number[i];
		i++;
	}
	i = 0;

	if(round_number(c_number, precision))
		v_int++;
	printf("%lld.",v_int);

while (i < precision)
	{
		printf("%hhd",c_number[i]);
		i++;
	}
	printf("\n");
	return (NULL);
}

int main()
{
	char *texto;
	long double f = 16.88888888888888;
	convert_char(f, 6);
	return (0);
}
