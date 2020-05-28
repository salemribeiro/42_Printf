/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/04/29 22:58:33 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	item;
	char	*mensage;
	int		i;

	va_start(item, format);
	mensage = NULL;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			mensage_buffer(format[i]);
		else
			i += specifier_options((char*)&format[i], va_arg(item, void*));
		i++;
	}
	mensage =  mensage_buffer('\0');
	printf("%s\n", mensage);
	free (mensage);
	va_end(item);
	return (0);
}

char	*mensage_buffer(char c)
{
	static char	*buffer;
	static int	i;

	if (!c && buffer)
		return (buffer);
	buffer = add_buffer(c, buffer, i);
	i++;
	return (buffer);
}

char	*add_buffer(char c, char *buffer, int size)
{
	int i;
	char *temp;

	i = 0;
	temp = calloc(size + 2, sizeof(c));
	if (buffer)
	{
		while (buffer[i])
		{
			temp[i] = buffer[i];
			i++;
		}
		free(buffer);
	}
	temp[i] = c;
	return (temp);
}
