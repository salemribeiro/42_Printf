/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/08/05 22:56:47 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		specifier_options(char *subtext)
{
	size_t	i;
	size_t	j;
	char	*jmp;

	i = 1;
	j = 0;
	jmp = 0;
	while (subtext[i])
	{
		while (FORBIDEN[j] && subtext[i] != FORBIDEN[j])
			j++;
		if (FORBIDEN[j])
		{
			parameters.specifier = FORBIDEN[j];
			jmp = flag_options(ft_substr(subtext, 1, i));
			jmp = width_options(jmp);
			jmp = precision_options(jmp);
			jmp = length_options(jmp);
			parameters.specifier = FORBIDEN[j];
			return(i + 1);
		}
		j = 0;
		i++;
	}
	return(0);
}
