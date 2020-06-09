/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 23:03:41 by sfreitas          #+#    #+#             */
/*   Updated: 2020/06/09 00:01:45 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list			item;
	struct hub_op	options;
	char			*text;

	va_start(item, format);
	while(search_percent((char*)format))
	{
		options = big_hub(-1, -1);
		if (options.width == -1)
			options = big_hub(va_arg(item, int), 2);
		if (options.precision == -1)
			options = big_hub(va_arg(item, int), 3);
		mensage_arg_solve(va_arg(item, void*), options.specifier);
		printf("%s", mensage_buffer('\0'));
		options = big_hub(0, 0);
	}
	va_end(item);
	return (0);
}

char		search_percent(char *text)
{
	static int	i;

	while (text[i])
	{
		if (text[i] != '%')
			mensage_buffer(text[i]);
		else
		{
			i += specifier_options((char*)&text[i]);
			return (text[i]);
		}
		i++;
	}
	return (text[i]);
}
