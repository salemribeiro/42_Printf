/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 13:19:01 by salem             #+#    #+#             */
/*   Updated: 2020/08/05 22:54:28 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	store_int(long long int value)
{
	char	*text;

	text = ft_itoa_base(convert_int(value), parameters.specifier);
	if (parameters.precision > 0 && ft_strlen(text))
		text = put_zero(text, parameters.precision);
	if ((parameters.flags & PLUS) == PLUS && value >= 0)
		text = ft_strjoin("+", text);
	if ((parameters.flags & SPACE) == SPACE)
		text = ft_strjoin(" ", text);
	send_buffer(text);
}

void	store_u_int(unsigned long long int value)
{
	char	*text;

	text = ft_u_itoa_base(convert_u_int(value), parameters.specifier);
	if (parameters.precision > 0 && ft_strlen(text))
		text = put_zero(text, parameters.precision);
	if ((parameters.flags & PLUS) == PLUS)
		text = ft_strjoin("+", text);
	if ((parameters.flags & SPACE) == SPACE)
		text = ft_strjoin(" ", text);
	send_buffer(text);
}

long long int	convert_int(long long int value)
{
	if (parameters.length == LONG)
		value  = (long long int)(long int)value;
	else if (parameters.length == 0)
		value = (long long int)(int)value;
	else if (parameters.length == H)
		value = (long long int)(short int)value;
	else if (parameters.length == HH)
		value = (long long int)(char)value;
	if (value < 0)
	{
		value = value * (-1);
		send_buffer("-");
	}
	return (value);
}

unsigned long long int	convert_u_int(unsigned long long int value)
{
	if (parameters.length == LONG)
		value  = (unsigned long long int)(unsigned long int)value;
	else if (parameters.length == 0)
		value = (unsigned long long int)(unsigned int)value;
	else if (parameters.length == H)
		value = (unsigned long long int)(unsigned short int)value;
	else if (parameters.length == HH)
		value = (unsigned long long int)(unsigned char)value;
	if ((parameters.flags & SPACE) == SPACE)
		parameters.flags = parameters.flags ^ SPACE;
	if ((parameters.flags & PLUS) == PLUS)
		parameters.flags = parameters.flags ^ PLUS;
	if ((parameters.flags & HASH ) == HASH && parameters.specifier == 'x')
		send_buffer("0x");
	if ((parameters.flags & HASH ) == HASH && parameters.specifier == 'X')
		send_buffer("0X");
	if ((parameters.flags & HASH ) == HASH && parameters.specifier == 'o')
		send_buffer("0");
	return (value);
}
