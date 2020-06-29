/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_arg_solve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 23:09:08 by sfreitas          #+#    #+#             */
/*   Updated: 2020/06/14 19:32:09 by sfreitas         ###   ########.fr       */
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
	text = ft_itoa((int)value);
	send_buffer(text);
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
	free (text);
	return (tmp);
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

