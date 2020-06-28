/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/06/27 23:55:08 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define SPECIFIER "diuoxXfFeEgGaAcspn%\0"
int		specifier_options(char *subtext)
{
	size_t	i;
	size_t	j;
	char	*jump;

	i = 1;
	j = 0;
	jump = 0;
	while (subtext[i])
	{
		while (SPECIFIER[j] && subtext[i] != SPECIFIER[j])
			j++;
		if (SPECIFIER[j])
		{
			jump = flag_options(ft_substr(subtext, 1, i), SPECIFIER[j]);
			jump = width_options(jump);
			jump = precision_options(jump, SPECIFIER[j]);
			jump = length_options(jump);
			big_hub (SPECIFIER[j], 5);
			return(i + 1);
		}
		j = 0;
		i++;
	}
	return(0);
}



