/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 21:46:59 by salem             #+#    #+#             */
/*   Updated: 2020/07/28 22:46:37 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int		ft_printstr(char *text)
{
	int i;
	int j;
	int k;
	char c;

	i = 0;
	j = 0;
	k = 0;
	c = '\0';
	while (text[i])
	{
		if (text[i] == -1)
		{
			write(1, &text[j], k);
			write(1,&c, 1);
			j = i + 1;
			k = -1;
		}
		i++;
		k++;
	}
	if (i > 0)
		write(1, &text[j], k);
	return (i);
}
