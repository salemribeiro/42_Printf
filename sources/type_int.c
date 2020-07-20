/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 13:19:01 by salem             #+#    #+#             */
/*   Updated: 2020/07/19 14:28:38 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	store_int (long long int value)
{
	t_options	opt;
	char		*text;
	char		c;

	opt = big_hub(-1, -1);
	text = ft_itoa(value);
	if (opt.precision > 0 && ft_strlen(text))
		text = put_zero(text, opt.precision);
	if ((opt.flags & PLUS) == PLUS)
		text = ft_strjoin("+", text);
	if ((opt.flags & SPACE) == SPACE)
		text = ft_strjoin(" ", text);
	send_buffer(text);
}

