/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_teste.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 23:20:06 by salem             #+#    #+#             */
/*   Updated: 2020/07/27 23:48:11 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

struct s_options
{
	char text[2048];
}typedef t_options;

t_options options;

void add_buffer(char c)
{
	static int i;

	if (i == 5 || c == '\0')
	{
		options.text[i] = '\0';
		printf("%s", options.text);
		i = 0;
	}
	if (i < 5)
	{
		options.text[i] = c;
		i++;
	}
}

int main(void)
{
	add_buffer('a');
	add_buffer('b');
	add_buffer('c');
	add_buffer('d');
	add_buffer('\n');
	add_buffer('1');
	add_buffer('2');
	add_buffer('\0');

	return (0);
}

