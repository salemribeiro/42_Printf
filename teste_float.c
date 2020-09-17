/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 19:26:26 by sfreitas          #+#    #+#             */
/*   Updated: 2020/09/07 20:32:28 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"



char	*convert_char(long double value, int precision)
{
	long long int		v_int;
	long double			v_doub;
	char				*c_number;
	int					i;
	char				flag;

	v_int = 0;
	v_doub = 0;
	i = 1;
	v_int = value;
	flag = 0;
	v_doub = v_doub - (unsigned long double)v_int;
	c_number = ft_calloc(precision + 1, sizeof(char));
	while (i < precision)
	{
		v_doub = v_doub * 10;
		c_number[i] = v_doub;
		v_doub = v_doub - c_number[i];
		i++;
	}
	i = 0;
	while (i < precision)
	{
		printf("%d -> %hhd\n", i, c_number[i]);
		i++;
	}

	return (NULL);
}

int main()
{
	char *texto;
	long double f = 16.7738996666661033;
	convert_char(f, 3);
	return (0);
}
