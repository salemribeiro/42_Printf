/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 23:03:41 by sfreitas          #+#    #+#             */
/*   Updated: 2020/07/18 23:36:10 by salem            ###   ########.fr       */
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
	t_options	opt;
	char		*text;

	va_start(item, format);
	while(search_percent((char*)format))
	{
		opt = big_hub(-1, -1);
		if (opt.width == -1)
			opt = big_hub(va_arg(item, int), 2);
		if (opt.precision == -1)
			opt = big_hub(va_arg(item, int), 3);
		message_arg_solve(item, opt.specifier);
		opt = big_hub(0, 0);
	}
	va_end(item);
	return (ft_printstr(message_buffer('\0')));
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
	return (text[i]);
}
