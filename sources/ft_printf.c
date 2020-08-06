/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 23:03:41 by sfreitas          #+#    #+#             */
/*   Updated: 2020/08/05 22:56:22 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Funcao responsavel por imprimir em tela tipos de dados diferentes dando a
** eles uma grande gama de opcoes de formatacao.
*/

int			ft_printf(const char *format, ...)
{
	va_list		item;
	int			len;

	va_start(item, format);
	len = 0;
	ft_bzero(parameters.text, 2048);
	while(search_percent((char*)format))
	{
		if (parameters.width == -1)
			parameters.width = va_arg(item, int);
		if (parameters.precision == -1)
			parameters.precision = va_arg(item, int);
		message_arg_solve(item, parameters.specifier);
	}
	message_buffer('\0');
	clear_struct();
	va_end(item);
	return (len);
}

/*
** Funcao responsavel por encontrar um valor inserido na string, faz isso
** buscando o caractere percent e depois desencadeando toda uma cadeia de
** funcoes que permitem tratar todos as opcoes para impressao dos valores
*/

char		search_percent(char *text)
{
	static int	i;

	while (text[i])
	{
		if (text[i] != '%')
			message_buffer(text[i]);
		else
		{
			i += specifier_options((char*)&text[i]);
			return (text[i]);
		}
		i++;
	}
	i = 0;
	return (0);
}
