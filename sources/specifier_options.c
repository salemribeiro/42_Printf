/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/08/17 21:09:45 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**   Funcao responsavel por localizar os parametros de tratamento dos dados
** a funcao recebe como parametro um ponteiro para uma substring do texto
** original que contem trecho dos parametros a serem tratados (Ex: %+0.2d)
** tendo como ordem [flag], [width], [precision], [length] e [specifier].
**   Retorna um inteiro para confirmacao da execucao correta.
*/

int		specifier_options(char *subtext)
{
	size_t	i;
	size_t	j;
	char	*jmp;
	char 	*tmp;

	i = 1;
	j = 0;
	jmp = 0;
	while (subtext[i])
	{
		while (SPECIFIERS[j] && subtext[i] != SPECIFIERS[j])
			j++;
		if (SPECIFIERS[j])
		{
			tmp = ft_substr(subtext, 1, i);
			jmp = flag_options(tmp, SPECIFIERS[j]);
			jmp = width_options(jmp);
			jmp = precision_options(jmp);
			jmp = length_options(jmp);
			g_opt.specifier = SPECIFIERS[j];
			free(tmp);
			return(i + 1);
		}
		j = 0;
		i++;
	}
	return(0);
}
