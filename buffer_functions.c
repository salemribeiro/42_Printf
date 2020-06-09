/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 23:47:21 by sfreitas          #+#    #+#             */
/*   Updated: 2020/06/08 23:47:26 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*mensage_buffer(char c)
{
	static char	*buffer;
	static int	i;

	buffer = add_buffer(c, buffer, i);
	i++;
	return (buffer);
}

char	*add_buffer(char c, char *buffer, int size)
{
	int i;
	char *temp;

	i = 0;
	temp = calloc(size + 2, sizeof(c));
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

struct hub_op	big_hub(int value, char field)
{
	static struct hub_op s_options;

	if (field == 0)
	{
		s_options.flags = 0;
		s_options.width = 0;
		s_options.precision = 0;
		s_options.length = 0;
		s_options.specifier = 0;
	}
	else if (field == 1)
		s_options.flags = value;
	else if (field == 2)
		s_options.width = value;
	else if (field == 3)
		s_options.precision = value;
	else if (field == 4)
		s_options.length = value;
	else if (field == 5)
		s_options.specifier = value;
	return (s_options);
}
