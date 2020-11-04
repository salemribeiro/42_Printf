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

void	store_char (long int  c)
{
	char	value[2];
	int		len;
	char	*tmp;
	int		width;

	tmp = NULL;
	if (c == '\0')
		value[0] = -1;
	else
		value[0] = c;
	value[1] = '\0';
	len = ft_strlen(value);
	width = g_opt.width;
	if (width > 0 && width > len)
	{
		tmp = manager_value(ft_strdup(""), width - len, ' ');
		if ((g_opt.flags & MINUS) == MINUS)
		{
			send_buffer(value);
			send_buffer(tmp);
		}
		else
		{
			send_buffer(tmp);
			send_buffer(value);
		}
	}
	else
	{
		send_buffer(value);
	}
	if (tmp)
		free(tmp);
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
