/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 23:47:21 by sfreitas          #+#    #+#             */
/*   Updated: 2020/07/30 23:49:49 by salem            ###   ########.fr       */
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

int		message_buffer(char c)
{
	static int	i;
	int			total;

	if (i == 5 || c == '\0')
	{
		parameters.text[i] = c;
		total = ft_printstr(parameters.text);
		i = 0;
		parameters.text[i] = '\0';
		return(total);
	}
	else if (i < 5)
	{
		parameters.text[i] = c;
	}
	i++;
	return(0);
}

void	clear_struct()
{
	parameters.flags = 0;
	parameters.width = 0;
	parameters.precision = 0;
	parameters.length = 0;
	parameters.specifier = 0;
	parameters.text[0] = '\0';
}
