/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wid_pre_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/11/29 13:04:53 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  Funcao recebe um ponteiro de char "*parameters" busca por informacoes do
** width envia essas informacoes para a estrutura global "opt.width" e avanca
** o ponteiro para posicao final de indicacao de width e retorna o mesmo.
*/

char	*width_options(char *parameters)
{
	int		i;
	int		width;
	char	*buffer;
	int		valid;

	i = 0;
	width = -1;
	buffer = NULL;
	valid = (*parameters == '-') ? -1 : 0;
	while (ft_isdigit(*parameters) || *parameters == '*')
	{
		buffer = add_buffer(*parameters, buffer, i++);
		parameters++;
	}
	if (buffer)
	{
		if (ft_isdigit(*buffer))
			width = ft_atoi(buffer);
		g_opt.width = width;
		free(buffer);
	}
	if (valid)
		g_opt.width = -1;
	return (parameters);
}

int		clear_precision_buffer(char **buffer, int precision)
{
	if (*buffer)
	{
		precision = ft_atoi(*buffer);
		free(*buffer);
	}
	return (precision);
}

/*
**  Funcao recebe um ponteiro de char "*parameters" busca por informacoes do
** precision envia essas informacoes para a estrutura global "opt.precision" e
** avanca o ponteiro para posicao final de indicacao de precision e retorna o
** mesmo.
*/

char	*precision_options(char *parameters)
{
	int		i;
	char	*buffer;
	int		precision;

	i = 0;
	buffer = NULL;
	precision = -2;
	if (*parameters == '.')
	{
		precision = 0;
		parameters++;
		if (ft_isdigit(*parameters))
		{
			while (ft_isdigit(*parameters))
			{
				buffer = add_buffer(*parameters, buffer, i++);
				parameters++;
			}
		}
		else if (*parameters == '*')
			precision = -1;
	}
	g_opt.precision = clear_precision_buffer(&buffer, precision);
	return (parameters);
}

/*
**  Funcao recebe um ponteiro de char "*parameters" busca por informacoes do
** length envia essas informacoes para a estrutura global "opt.length" e
** avanca o ponteiro para posicao final de indicacao de length e retorna o
** mesmo.
*/

char	*length_options(char *parameters)
{
	int		i;
	int		length;
	char	*buffer;

	i = 0;
	buffer = NULL;
	length = -1;
	if (*parameters)
	{
		while (*parameters == 'h' || *parameters == 'l' || *parameters == 'j' ||
			*parameters == 'z' || *parameters == 't' || *parameters == 'L')
		{
			buffer = add_buffer(*parameters, buffer, i);
			length = (int)*((short int*)buffer);
			parameters++;
			i++;
		}
		if (length == LLONG || length == H || length == J || length == LONG ||
		length == T || length == Z || length == HH || length == LL)
			length = (int)*((short int*)buffer);
		g_opt.length = length;
	}
	if (buffer != NULL)
		free(buffer);
	return (parameters);
}
