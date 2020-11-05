/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 23:03:41 by sfreitas          #+#    #+#             */
/*   Updated: 2020/08/17 23:38:24 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			resolve_negative(int value, char option)
{
	if (value < 0 && option == 0)
	{
		value = value * (-1);
		if ((g_opt.flags & MINUS) != MINUS)
			g_opt.flags = g_opt.flags ^ MINUS;
	}
	else if (value < 0 && option == 1)
		value = -2;
	return(value);
}


/*
** Funcao responsavel por imprimir em tela tipos de dados diferentes dando a
** eles uma grande gama de opcoes de formatacao.
*/

int			ft_printf(const char *format, ...)
{
	va_list		item;
	int			len;
	clear_struct(1);
	va_start(item, format);
	len = 0;
	while(search_percent((char*)format))
	{
		if (g_opt.specifier == '\0')
		{
			g_opt.count = -1;
			break;
		}
		if (g_opt.width == -1)
			g_opt.width = resolve_negative(va_arg(item, int), 0);
		if (g_opt.precision == -1)
			g_opt.precision = resolve_negative(va_arg(item, int), 1);
		message_arg_solve(item);
		clear_struct(0);
	}
	message_buffer('\0');
	len = g_opt.count;
	g_opt.count = 0;
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
		if (text[i] == '%')
		{
			i += specifier_options((char*)&text[i]);
			return (1);
		}
		else
			message_buffer(text[i]);
		i++;
	}
	i = 0;
	return (0);
}
