/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesage_arg_solve.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 23:09:08 by sfreitas          #+#    #+#             */
/*   Updated: 2020/06/08 23:58:37 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mensage_arg_solve(void *value, char specifier)
{
	if (specifier == 'd' || specifier == 'i')
		store_int(value);
}
//Tratamento dos argumentos
void	store_int (void *value)
{
	int		number;
	char	*text;

	number = (int)value;
	text = ft_itoa(number);
}

void	send_buffer(char *text)
{
	int i;

	i = 0;
	while (text[i])
	{
		mensage_buffer(text[i]);
		i++;
	}
}
