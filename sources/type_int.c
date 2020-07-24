/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 13:19:01 by salem             #+#    #+#             */
/*   Updated: 2020/07/23 22:42:21 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	store_int (long long int value)
{
	t_options	opt;
	char		*text;
	char		c;

	opt = big_hub(-1, -1);
	if (opt.length == LONG)
		value = (long long int)(long int) value;
	else if (opt.length == HH)
		value = (long long int)(char) value;
	else if (opt.length == H)
		value = (long long int)(short int) value;
	if (value < 0)
		send_buffer("-");
	text = ft_itoa_base(value, opt.specifier);
	
	if (opt.precision > 0 && ft_strlen(text))
		text = put_zero(text, opt.precision);
	if ((opt.flags & PLUS) == PLUS && value >= 0)
		text = ft_strjoin("+", text);
	if ((opt.flags & SPACE) == SPACE)
		text = ft_strjoin(" ", text);

	send_buffer(text);
}

