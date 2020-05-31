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
	char	width;

	buffer = NULL;
	p_null = NULL;
	flags = '\0';
	i = 0;
	width = -1;
	while (ft_isdigit(*f) || *f == '*')
	{
		buffer = add_buffer(*f, buffer, i);
		f++;
		i++;
	}
	if (ft_isdigit(*buffer))
		width = ft_atoi(buffer);
	big_hub(&flags, &width, &flags, &flags);
	return (f);
}

char	*precision_options(char *f, char specifier)
{
	char		*buffer;
	char		c_null;
	char		precision;
	int			i;

	buffer = NULL;
	i = 0;
	precision = -1;
	if (specifier != 'c' &&  specifier != 'p')
	{
		while (ft_isdigit(*f) || *f == '*' || *f == '.')
		{
			if (*f != '.')
			{
				buffer = add_buffer(*f, buffer, i);
				i++;
			}
			f++;
		}
		if (ft_isdigit(*buffer))
			precision = ft_atoi(buffer);
		big_hub(&c_null, &c_null, &precision, &c_null);
		return (f);
	}
	else
		return (buffer);
}

char	*length_options(char *f)
{
	char		*buffer;
	char		c_null;
	short int	length;
	int			i;

	buffer = NULL;
	c_null = 0;
	i = 0;
	length = 0;
	if (*f)
	{
		while (*f == 'h' || *f == 'l' || *f == 'j' ||
			*f == 'z' || *f == 't' || *f =='L')
		{
			buffer = add_buffer(*f, buffer, i);
			f++;
			i++;
		}
		length = (short int*)buffer;
		if (length != 76 && length != 104 && length != 106 &&
			length != 108 && length != 116 && length != 122 &&
			length != 26728 && length == 27756)
			length = 0;
	big_hub(&c_null, &c_null, &c_null, &length);
		return (f);
	}
	else
		return (buffer);
}
