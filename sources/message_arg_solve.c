/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_arg_solve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 23:09:08 by sfreitas          #+#    #+#             */
/*   Updated: 2020/08/11 22:08:09 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
** Funcao responsavel por verificar e enviar os dados recebidos via args
** para sua função de tratamento correspondente
*/

void	message_arg_solve(va_list item)
{
	if (parameters.specifier == 'd' || parameters.specifier == 'i')
	{
		if (parameters.length == LL)
			store_int(va_arg(item, long long int));
		else if (parameters.length == LONG)
			store_int(va_arg(item, long int));
		else
			store_int(va_arg(item, int));
	}
	else if (parameters.specifier == 'u' || parameters.specifier == 'x' ||
	parameters.specifier == 'X' || parameters.specifier == 'o')
		store_u_int(va_arg(item, unsigned long long int));
	else if (parameters.specifier == 'c')
		store_char(va_arg(item, int));
	else if (parameters.specifier == 's')
		store_string(va_arg(item, char*));
}

char	*put_zero(char *source, int total)
{
	int		i;
	int		size;
	char	*tmp;
	char	*text;

	i = 0;
	size = total - ft_strlen(source);
	text = ft_calloc(size, sizeof(char));
	while (i < size)
		text[i++] = '0';
	text[i] = '\0';
	tmp = ft_strjoin(text, source);
	free(text);
	return (tmp);
}

char	*resize_result(char *result, char c, int size)
{
	int		i;
	int		t_size;
	char	*tmp;

	i = 0;
	t_size = ft_strlen(result);
	if (t_size < size)
		return(result);
	tmp = (char*)calloc(size, t_size);
	while (i < size)
	{
		tmp[i] = c;
		i++;
	}
	ft_strlcpy(&tmp[i], result, t_size);
	free(result);
	return (tmp);
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

