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
			jump = precision_options(jump);
			return(i);
		}
		j = 0;
		i++;
	}
	return(0);
}

char	*width_options(char *f)
{
	char	*buffer;
	int		i;
	buffer = NULL;
	i = 0;
	while ((*f >= '0' && *f <= '9') || *f == '*')
	{
		buffer = add_buffer(*f, buffer, i);
		f++;
		i++;
	}
	return (f);
}

char	*precision_options(char *f)
{
	char	*buffer;
	int		i;
	buffer = NULL;
	i = 0;
	while ((*f >= '0' && *f <= '9') || *f == '*' || *f == '.')
	{
		buffer = add_buffer(*f, buffer, i);
		f++;
		i++;
	}
	return (f);
}
