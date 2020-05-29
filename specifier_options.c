/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/04/29 22:58:33 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		specifier_options(char *subtext, void *arg)
{
	size_t	i;
	size_t	j;
	char	*jump;
	char	specifier[20];

	i = 1;
	j = 0;
	jump = 0;
	ft_strlcpy(specifier,"diuoxXfFeEgGaAcspn%", 20);
	while (subtext[i])
	{
		while (specifier[j] && subtext[i] != specifier[j])
			j++;
		if (specifier[j])
		{
			jump = flag_options(ft_substr(subtext, 1, i), specifier[j]);
			jump = width_options(jump);
			jump = precision_options(jump, specifier[i]);
			return(i);
		}
		j = 0;
		i++;
	}
	return(0);
}


