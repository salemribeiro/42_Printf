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

#include "ft_printf.h"

void	store_float(long double value)
{
	if (value < 0)
	{
		message_buffer('-');
		value = value * (-1);
	}
	convert_char(value, g_opt.precision);
}

void	convert_char(long double value, int precision)
{
	long long int	v_int;
	long double	v_doub;
	char			*c_number;
	int				i;

	i = 0;
	v_int = (long long int)value;
	v_doub = value - (long double)(long long int)value;
	c_number = ft_calloc(precision + 2, sizeof(char));
	while (i <= precision)
	{
		v_doub = v_doub * 10;
		c_number[i] = (char)v_doub;
		v_doub = v_doub - (long double)c_number[i];
		i++;
	}
	if(round_number(c_number, precision))
		v_int++;
	sum_one(c_number, precision);
	send_buffer(ft_itoa(v_int));
	message_buffer('.');
	send_buffer(c_number);
}

char	round_number(char *value, int precision)
{
	int i;

	i = precision;
	while ((i >= 0 && value[i] >= 5) || value[i] == -1)
	{
		if ((value[i] >= 5 && i > 0) || (value[i] == -1 && i > 0))
		{
			if (value[i - 1] < 9)
			{
				value[i - 1]++;
				return (0);
			}
			else if (value[i - 1] == 9)
			{
				value[i - 1] = -1;
			}
		}
		else if ((value[i] >= 5 && i == 0) || (value[i] == -1 && i ==0))
			return (1);
		i--;
	}
	return (0);
}

char	*sum_one(char *value, int precision)
{
	int i;

	i = 0;
	while (i < precision)
	{
		if (value[i] == -1)
			value[i]++;
		value[i] += 48;
		i++;
	}
	return value;
}
