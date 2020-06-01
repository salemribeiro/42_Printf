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
	int		c_null;
	int		i;
	int		width;

	buffer = NULL;
	c_null = 0;
	i = 0;
	width = -1;
	while (ft_isdigit(*f) || *f == '*')
	{
		buffer = add_buffer(*f, buffer, i);
		f++;
		i++;
	}
	if (buffer)
	{
		if (ft_isdigit(*buffer))
			width = ft_atoi(buffer);
		big_hub(&c_null, &width, &c_null, &c_null);
	}
	return (f);
}

char	*precision_options(char *f, char specifier)
{
	char	*buffer;
	int		c_null;
	int		precision;
	int		i;

	buffer = NULL;
	i = 0;
	precision = -1;
	c_null = 0;
	while (ft_isdigit(*f) || *f == '*' || *f == '.')
	{
		if (*f != '.')
		{
			buffer = add_buffer(*f, buffer, i);
			i++;
		}
		f++;
	}
	if (specifier == 'c' ||  specifier == 'p' || specifier == 'd' ||
		specifier == 'i')
		return (f);
	if (ft_isdigit(*buffer))
		precision = ft_atoi(buffer);
	big_hub(&c_null, &c_null, &precision, &c_null);
	return (f);
}

char	*length_options(char *f)
{
	char	*buffer;
	int		c_null;
	int		l;
	int		i;

	buffer = NULL;
	c_null = 0;
	i = 0;
	if (*f)
	{
		while (*f == 'h' || *f == 'l' || *f == 'j' ||
			*f == 'z' || *f == 't' || *f =='L')
		{
			buffer = add_buffer(*f, buffer, i);
			l = (int)*((short int*)buffer);
			f++;
			i++;
		}
		if (l == 76 || l == 104 || l == 106 ||l == 108 || l == 116 ||
		l == 122 || l == 26728 || l == 27756)
			l = (int)*((short int*)buffer);
		big_hub(&c_null, &c_null, &c_null, &l);
	}
		return (f);
}
