/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 23:47:21 by sfreitas          #+#    #+#             */
/*   Updated: 2020/09/02 00:29:01 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  Funcao recebe um caracter c, um ponteiro para uma string e um inteiro
** que informa o tamanho da string recebida.
**  Ela reponsavel por unir o ponteiro de char com o caractere recebido
** retornando o resultado dessa união.
*/

char	*add_buffer(char c, char *buffer, int size)
{
	int i;
	char *temp;

	i = 0;
	temp = ft_calloc(size + 2, sizeof(c));
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
**  Funcao recebe um caracter e armazena em um buffer com o tamanho de 2048
** bits, retorna 0 caso nao seja realizada a chamada de impressao ou o numero
** de caracteres impressos.
*/

int		message_buffer(char c)
{
	static int	i;
	int			total;

	total = 0;
	if (i == 5 || c == '\0')
	{
		g_opt.text[i] = c;
		total = ft_printstr(g_opt.text);
		i = 0;
		g_opt.text[i] = '\0';
		return(total);
	}
	else if (i < 5)
	{
		g_opt.text[i] = c;
	}
	i++;
	return(0);
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

/*
**  Funcao tem por finalidade limpar a estrutra da variavel global (g_opt)
*/

void	clear_struct()
{
	int i;

	i = 0;
	g_opt.flags = 0;
	g_opt.width = 0;
	g_opt.precision = 0;
	g_opt.length = 0;
	g_opt.specifier = 0;
	while(i < 2048)
		g_opt.text[i++] = '\0';
	g_opt.count = 0;
}
