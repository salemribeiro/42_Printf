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
	char	value[2];

	if (c == '\0')
		value[0] = -1;
	else
		value[0] = c;
	value[1] = '\0';
	send_buffer(value);
}

void	store_percent(int width, char flags)
{
	char	*tmp;

	tmp = NULL;
	if (width > 0)
	{
		if ((flags & ZERO) != ZERO)
			tmp = manager_value(ft_strdup(""), width - 1, ' ');
		else
			tmp = manager_value(ft_strdup(""), width - 1, '0');
		if ((flags & MINUS) != MINUS)
			send_buffer(tmp);
		message_buffer('%');
		if ((flags & MINUS) == MINUS)
				send_buffer(tmp);
		if (tmp)
			free(tmp);
	}
	else
		message_buffer('%');
}
