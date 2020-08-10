/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_and_precision_options.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/08/09 12:17:01 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Funcao responsavel verificar e catalogar os parametros de width
*/

char	*width_options(char *f)
{
	int		i;
	int		width;
	char	*buffer;

	i = 0;
	width = -1;
	buffer = NULL;
	while (ft_isdigit(*f) || *f == '*')
		buffer = add_buffer(*f++, buffer, i++);
	if (buffer)
	{
		if (ft_isdigit(*buffer))
			width = ft_atoi(buffer);
		parameters.width = width;
		free(buffer);
	}
	return (f);
}

/*
** Funcao responsavel verificar e catalogar os parametros de precision
*/

char	*precision_options(char *f)
{
	int		i;
	char	*buffer;
	int		precision;

	i = 0;
	buffer = NULL;
	precision = -1;
	while (ft_isdigit(*f) || *f == '*' || *f == '.')
	{
		if (*f != '.')
		{
			buffer = add_buffer(*f, buffer, i);
			i++;
		}
		f++;
	}
	if (buffer)
	{
		if (ft_isdigit(*buffer))
			precision = ft_atoi(buffer);
		parameters.precision = precision;
		free(buffer);
	}
	return (f);
}

/*
** Funcao responsavel verificar e catalogar os parametros de length
*/

char	*length_options(char *f)
{
	int		i;
	int		length;
	char	*buffer;

	i = 0;
	buffer = NULL;
	length = -1;
	if (*f)
	{
		while (*f == 'h' || *f == 'l' || *f == 'j' ||
			*f == 'z' || *f == 't' || *f =='L')
		{
			buffer = add_buffer(*f, buffer, i);
			length = (int)*((short int*)buffer);
			f++;
			i++;
		}
		if (length == LLONG || length == H || length == J || length == LONG ||
		length == T || length == Z || length == HH || length == LL)
			length = (int)*((short int*)buffer);
		parameters.length = length;
	}
	if (buffer != NULL)
		free(buffer);
	return (f);
}
