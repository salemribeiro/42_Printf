/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_options_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 22:30:59 by salem             #+#    #+#             */
/*   Updated: 2020/11/30 22:31:16 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*get_parameters(char specifier, char *jmp, char *tmp)
{
	jmp = flag_options(tmp, specifier);
	jmp = width_options(jmp);
	jmp = precision_options(jmp);
	jmp = length_options(jmp);
	g_opt.specifier = specifier;
	return (jmp);
}

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
	char	*tmp;

	i = 1;
	j = 0;
	jmp = NULL;
	tmp = NULL;
	while (subtext[i])
	{
		while (SPECIFIERS[j] && subtext[i] != SPECIFIERS[j])
			j++;
		if (SPECIFIERS[j])
		{
			tmp = ft_substr(subtext, 1, i);
			jmp = get_parameters(SPECIFIERS[j], jmp, tmp);
			free(tmp);
			return (i + 1);
		}
		j = 0;
		i++;
	}
	return (0);
}
