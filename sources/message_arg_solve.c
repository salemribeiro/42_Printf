/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_arg_solve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 23:09:08 by sfreitas          #+#    #+#             */
/*   Updated: 2020/06/14 17:30:28 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Funcao ficara responsavel por verificar e enviar os dados recebidos via args
** para sua função de tratamento correspondente
*/

void	message_arg_solve(void *value, char specifier)
{
	if (specifier == 'd' || specifier == 'i')
		store_int(value);
}

/*
** Tratamento de argumento do tipo inteiro
*/

void	store_int (void *value)
{
	struct hub_op	s_opt;
	char			*text;
	char			c;

	s_opt = big_hub(-1, -1);
	if ((s_opt.flag & 8) == 8)
	text = resize_result(ft_itoa((int)value), ;
	
	send_buffer(text);
}

char	*resize_result(char *result, char c, int size)
{
	int		i;
	int		t_size;
	char	*temp;

	i = 0;
	t_size = ft_strlen(result);
	if (t_size < size)
		return(result);
	temp = (char*)calloc(size, t_size);
	while (i < size)
	{
		temp[i] = c;
		i++;
	}
	ft_strlcpy(&temp[i], result, t_size);
	free(result);
	return (temp);
}





/*
** Envio de valores para o buffer de messagem
*/

void	send_buffer(char *text)
{
	int i;

	i = 0;
	while (text[i])
	{
		message_buffer(text[i]);
		i++;
	}
}

