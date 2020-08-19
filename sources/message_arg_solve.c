/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_arg_solve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 23:09:08 by sfreitas          #+#    #+#             */
/*   Updated: 2020/08/18 23:30:38 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Funcao responsavel por verificar e enviar os dados recebidos via args
** para sua função de tratamento correspondente
*/

void	message_arg_solve(va_list item)
{
	if (g_opt.specifier == 'd' || g_opt.specifier == 'i')
	{
		if (g_opt.length == LL)
			store_int(va_arg(item, long long int));
		else if (g_opt.length == LONG)
			store_int(va_arg(item, long int));
		else
			store_int(va_arg(item, int));
	}
	else if (g_opt.specifier == 'u' || g_opt.specifier == 'x' ||
	g_opt.specifier == 'X' || g_opt.specifier == 'o')
		store_u_int(va_arg(item, unsigned long long int));
	else if (g_opt.specifier == 'c')
		store_char(va_arg(item, int));
	else if (g_opt.specifier == 's')
		store_string(va_arg(item, char*));
}

/*
*   Funcao recebe como parametro um ponteiro "*source", um caracter "c" e
** um inteiro "total".
**  E responsavel por criar um novo ponteiro de tamanho "total", contendo o
** conteudo dos valores de "*source" completados com "c".
*/

char	*manager_precision(char *source, int total)
{
	int		i;
	int		size;
	char	*tmp;
	char	*text;

	i = 0;
	size = total - ft_strlen(source);
	if (size <= 0)
		return (source);
	text = ft_calloc(size, sizeof(char));
	while (i < size)
		text[i++] = '0';
	text[i] = '\0';
	tmp = ft_strjoin(text, source);
	free(text);
	free(source);
	return (tmp);
}

char	*manager_width(char *source, int total)
{
	int		i;
	int		size;
	char	*tmp;
	char	*text;

	i = 0;
	size = total - ft_strlen(source);
	if (size <= 0)
		return (source);
	text = ft_calloc(size, sizeof(char));
	while (i < size)
		text[i++] = ' ';
	text[i] = '\0';
	tmp = ft_strjoin(text, source);
	free(text);
	free(source);
	return (tmp);
}

// VER A REAL NECESSIDADE DESSA FUNÇÃO CASO NÃO FOR NECESSÁRIA DEVE SER EXCLUÍDA

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
