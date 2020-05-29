/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_and_precision_options.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/04/29 22:58:33 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char	*precision_options(char *f, char specifier)
{
	char	*buffer;
	int		i;
	buffer = NULL;
	i = 0;
	if (specifier != 'c' &&  specifier != 'p')
		return (buffer);
	while ((*f >= '0' && *f <= '9') || *f == '*' || *f == '.')
	{
		buffer = add_buffer(*f, buffer, i);
		f++;
		i++;
	}
	return (f);
}
