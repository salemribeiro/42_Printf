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
	int		flags;
	int		width;
	int		precision;
	int		length;

	flags = 0;
	width = 0;
	precision = 0;
	length = 0;

	va_start(item, format);
	mensage = NULL;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			mensage_buffer(format[i]);
		else
			i += specifier_options((char*)&format[i]);
		i++;
	}
	mensage =  mensage_buffer('\0');
	big_hub(&flags, &width, &precision, &length);
	printf("FLAGS: %d | WIDTH: %d | PRECISION: %d | LENGTH: %d\n", flags, width, precision, length);
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

void	big_hub(int *flags, int *width, int *precision, int *length)
{
	static int	s_flags;
	static int	s_width;
	static int	s_precision;
	static int	s_length;

	if (*flags == 0 && *width == 0 && *precision == 0 && *length == 0)
	{
		*flags = s_flags;
		*width = s_width;
		*precision = s_precision;
		*length = s_length;
	}
	else
	{
		if (*flags)
			s_flags = *flags;
		if (*width)
			s_width = *width;
		if (*precision)
			s_precision = *precision;
		if (*length)
			s_length = *length;
	}
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
