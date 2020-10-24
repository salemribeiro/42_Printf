/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 13:18:40 by salem             #+#    #+#             */
/*   Updated: 2020/07/19 13:18:42 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	store_char (char c)
{
	char value[2];
	if (c == '\0')
		value[0] = -1;
	else
		value[0] = c;
	value[1] = '\0';
	send_buffer(value);
}

void	store_percent()
{
	char *text;

	text = NULL;
/*	if (g_opt.precision > 0)
		text = manager_precision(ft_strdup("0"), g_opt.precision);
	if (g_opt.width > 0)
		text = manager_width(ft_strdup(""), g_opt.width);
	if (text)
		send_buffer(text);
*/
	message_buffer('%');
}

