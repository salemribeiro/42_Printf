/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesage_arg_solve.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 23:09:08 by sfreitas          #+#    #+#             */
/*   Updated: 2020/06/08 23:58:37 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Funcao ficara responsavel por verificar e enviar os dados recebidos via args
** para sua função de tratamento correspondente
*/

void	mensage_arg_solve(void *value, char specifier)
{
	if (specifier == 'd' || specifier == 'i')
		store_int(value);
}

/*
** Tratamento de argumento do tipo inteiro
*/

void	store_int (void *value)
{
	int		number;
	char	*text;

	number = (int)value;
	text = ft_itoa(number);
	send_buffer(text);
}

/*
** Envio de valores para o buffer de mensagem
*/

void	send_buffer(char *text)
{
	int i;

	i = 0;
	while (text[i])
	{
		mensage_buffer(text[i]);
		i++;
	}
}
