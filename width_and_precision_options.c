/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_and_precision_options.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/04/29 22:58:33 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*width_options(char *f)
{
	char	*buffer;
	char	*p_null;
	char	flags;
	int		i;

	buffer = NULL;
	p_null = NULL;
	flags = '\0';
	i = 0;
	while ((*f >= '0' && *f <= '9') || *f == '*')
	{
		buffer = add_buffer(*f, buffer, i);
		f++;
		i++;
	}
	big_hub(&flags, &buffer, &p_null, &p_null);
	return (f);
}

char	*precision_options(char *f, char specifier)
{
	char	*buffer;
	char	*p_null;
	char	flags;
	int		i;

	buffer = NULL;
	p_null = NULL;
	flags = '\0';
	i = 0;
	if (specifier != 'c' &&  specifier != 'p')
	{
		while ((*f >= '0' && *f <= '9') || *f == '*' || *f == '.')
		{
			buffer = add_buffer(*f, buffer, i);
			f++;
			i++;
		}
		big_hub(&flags, &p_null, &buffer, &p_null);
		return (f);
	}
	else
		return (buffer);
}

char	*length_options(char *f)
{
	char	*buffer;
	char	*p_null;
	char	flags;
	int		i;

	buffer = NULL;
	p_null = NULL;
	flags = 0;
	i = 0;
	if (*f)
	{
		while (*f == 'h' || *f == 'l' || *f == 'j' ||
			*f == 'z' || *f == 't' || *f =='L')
		{
			buffer = add_buffer(*f, buffer, i);
			f++;
			i++;
		}
		big_hub(&flags, &p_null, &p_null, &buffer);
		return (f);
	}
	else
		return (buffer);
}
