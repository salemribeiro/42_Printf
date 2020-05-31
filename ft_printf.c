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
	char flags;
	char *width;
	char *precision;
	char *length;

	flags = '\0';
	width = NULL;
	precision = NULL;
	length = NULL;

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
	printf("FLAGS: %d | WIDTH: %s | PRECISION: %s | LENGTH: %s\n", flags, width, precision, length);
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

void	big_hub(char *flags, char **width, char **precision, char **length)
{
	static char s_flags;
	static char *s_width;
	static char *s_precision;
	static char *s_length;

	if (*flags == 0 && *width == NULL && precision == NULL && *length == NULL)
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
