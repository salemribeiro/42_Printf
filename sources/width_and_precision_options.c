/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_and_precision_options.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/06/28 15:12:36 by salem            ###   ########.fr       */
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
	{
		buffer = add_buffer(*f, buffer, i);
		f++;
		i++;
	}
	if (buffer)
	{
		if (ft_isdigit(*buffer))
			width = ft_atoi(buffer);
		big_hub(width, 2);
	}
	return (f);
}

/*
** Funcao responsavel verificar e catalogar os parametros de precision
*/

char	*precision_options(char *f, char specifier)
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
		big_hub(precision, 3);
	}
	return (f);
}

/*
** Funcao responsavel verificar e catalogar os parametros de length
*/

char	*length_options(char *f)
{
	int		i;
	int		l;
	char	*buffer;

	i = 0;
	buffer = NULL;
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
		if (l == 0x4C || l == 0x68 || l == 0x6A || l == 0x6C || l == 0x74 ||
		l == 0x7A || l == 0x6868 || l == 0x6C6C)
			l = (int)*((short int*)buffer);
		big_hub(l, 4);
	}
		return (f);
}
