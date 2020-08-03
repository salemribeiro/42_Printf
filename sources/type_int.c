/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 13:19:01 by salem             #+#    #+#             */
/*   Updated: 2020/08/02 22:45:21 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			store_int (long long int value)
{
	unsigned long long int	tmp;
	char					*text;
	char					c;

	text = ft_itoa_base(convert_int(value), parameters.specifier);

	if (parameters.precision > 0 && ft_strlen(text))
		text = put_zero(text, parameters.precision);
	if ((parameters.flags & PLUS) == PLUS && value >= 0)
		text = ft_strjoin("+", text);
	if ((parameters.flags & SPACE) == SPACE)
		text = ft_strjoin(" ", text);
	send_buffer(text);
}

long long int	convert_int(long long int value)
{
	unsigned long long int	tmp;

	tmp = 0;
	if (parameters.length == LONG)
		value = (long long int)(long int)value;
	else if (parameters.length == 0)
		value = (long long int)(int)value;
	else if (parameters.length == H)
		value = (long long int)(short int)value;
	else if (parameters.length == HH)
		value = (long long int)(char)value;
	if (value < 0 && parameters.specifier != 'x' && parameters.specifier != 'X')
	{
		send_buffer("-");
		value = value * (-1);
	}
	else if (parameters.specifier == 'x' || parameters.specifier == 'X')
	{
		tmp = value;
		tmp = tmp & value;
	}
	return (value);
}
