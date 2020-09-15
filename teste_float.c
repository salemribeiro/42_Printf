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



char	*convert_char(long long double value, int precision)
{
	long long int		v_int;
	long long double	v_doub;
	char				*c_number;
	int					i;
	char				flag;

	v_int = 0;
	v_doub = 0;
	i = 0;
	v_int = value;
	flag = 0;
	v_doub = v_doub - (long long double)v_int;
	c_number = ft_calloc(precision + 1, size_t(char));
	while (i < precision)
	{
		
		c_number[i] = 
		i++;
	}





}

int main()
{
	char *texto;
	long double f = 16.7738996666661033;

	return (0);
}
