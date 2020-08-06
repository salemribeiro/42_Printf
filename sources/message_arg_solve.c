/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_arg_solve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 23:09:08 by sfreitas          #+#    #+#             */
/*   Updated: 2020/08/03 23:33:57 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
** Funcao responsavel por verificar e enviar os dados recebidos via args
** para sua função de tratamento correspondente
*/

void	message_arg_solve(va_list item, char specifier)
{
	if (specifier == 'd' || specifier == 'i')
		store_int(va_arg(item, long long int));
	else if (specifier == 'u' || specifier == 'x' || specifier == 'X' ||
	specifier == 'o')
		store_u_int(va_arg(item, unsigned long long int));
	else if (specifier == 'c')
		store_char(va_arg(item, int));
	else if (specifier == 's')
		store_string(va_arg(item, char*));
}

char	*put_zero(char *source, int total)
{
	int		i;
	int		size;
	char	*tmp;
	char	text[total + 1];

	i = 0;
	size = total - ft_strlen(source);
	while (i < size)
		text[i++] = '0';
	text[i] = '\0';
	tmp = ft_strjoin(text, source);
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

