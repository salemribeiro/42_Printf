/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 13:19:01 by salem             #+#    #+#             */
/*   Updated: 2020/07/28 21:00:24 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	store_int (long long int value)
{
	char		*text;
	char		c;

	if (parameters.length == LONG)
		value = (long long int)(long int) value;
	else if (parameters.length == HH)
		value = (long long int)(char) value;
	else if (parameters.length == H)
		value = (long long int)(short int) value;
	if (value < 0)
		send_buffer("-");
	text = ft_itoa_base(value, parameters.specifier);
	
	if (parameters.precision > 0 && ft_strlen(text))
		text = put_zero(text, parameters.precision);
	if ((parameters.flags & PLUS) == PLUS && value >= 0)
		text = ft_strjoin("+", text);
	if ((parameters.flags & SPACE) == SPACE)
		text = ft_strjoin(" ", text);
	send_buffer(text);
}

