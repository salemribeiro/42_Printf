/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 21:46:59 by salem             #+#    #+#             */
/*   Updated: 2020/08/17 21:16:19 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int		ft_printstr(char *text, int size)
{
	g_opt.count += (int)write(1, &text[0], size);
	return (size);
}

void	create_buffer()
{
	int i;

	i = 0;
	while (i < 2048)
		g_opt.text[i++] = '\0';
}

