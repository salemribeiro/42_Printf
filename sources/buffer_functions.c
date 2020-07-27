/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 23:47:21 by sfreitas          #+#    #+#             */
/*   Updated: 2020/07/25 19:00:18 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Funcao atua para unir os caracteres e enviar como retorno
*/

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

/*
** Funcao responsavel por armazenar o buffer de messagem
*/

char		*message_buffer(char c)
{
	static int	i;
	static char	*buffer;

	if (c >= 0)
	{
		buffer = add_buffer(c, buffer, i);
		i++;
	}
	else
	{
		free(buffer);
		buffer = NULL;
		i = 0;
	}
	return (buffer);
}

/*
** Funcao responsavel por armazenar dados de tratamento dos parametros
** enviados em args
*/

t_options	big_hub(int value, char field)
{
	static t_options opt;

	if (field == 0)
	{
		opt.flags = 0;
		opt.width = 0;
		opt.precision = 0;
		opt.length = 0;
		opt.specifier = 0;
	}
	else if (field == 1)
		opt.flags = value;
	else if (field == 2)
		opt.width = value;
	else if (field == 3)
		opt.precision = value;
	else if (field == 4)
		opt.length = value;
	else if (field == 5)
		opt.specifier = value;
	return (opt);
}
