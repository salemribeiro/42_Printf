/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/08/09 12:11:28 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		while (FORBIDEN[j] && subtext[i] != FORBIDEN[j])
			j++;
		if (FORBIDEN[j])
		{
			tmp = ft_substr(subtext, 1, i);
			jmp = flag_options(tmp);
			jmp = width_options(jmp);
			jmp = precision_options(jmp);
			jmp = length_options(jmp);
			parameters.specifier = FORBIDEN[j];
			free(tmp);
			return(i + 1);
		}
		j = 0;
		i++;
	}
	return(0);
}
