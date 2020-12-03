/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:27:58 by salem             #+#    #+#             */
/*   Updated: 2020/12/03 20:06:01 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int		ft_printstr(char *text, int size)
{
	g_opt.count += (int)write(1, &text[0], size);
	return (size);
}

int		create_buffer(void)
{
	int i;

	i = 0;
	while (i < 2048)
		g_opt.text[i++] = '\0';
	return (0);
}
