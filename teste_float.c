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


int	solve_round(long double *value, int precision)
{
	long long int	ibase;
	long double		fbase;
	int				i;

	i = 0;
	fbase = *value;
	ibase = fbase;
	fbase = (fbase - (long long double)ibase) * 10;
	while (i < precision && fbase >= 0)
	{
		
		i++;
	}
	

	ibase = value;
	f
	return (0);
}

int	type_float(long double fbase, int precision)
{
	char			*text;
	long long int	ibase;
	int				i;

	ibase = fbase;
	text = ft_itoa(ibase);
	fbase = (fbase - (long double)ibase);
	if (solve_round(&fbase, precision);
		ibase++;
	text = ft_strjoin(text, ".");
}




int main()
{
	char *texto;
	long double f = 16.7738996666661033;
	long long int i;
	int count;
	int precision;

	printf("O valor real é %.0Lf\n", f);
	precision = 8;
	count = 0;
	i = f;
	texto = ft_itoa(i);
	f = (f - (double)i) * 10;
	texto = ft_strjoin(texto, ".");
	i = f;
	while (f >= 0 && count < (precision - 2))
	{
		texto = ft_strjoin(texto, ft_itoa(i));
		f = (f - (double)i) * 10;
		i = f;
		count ++;
	}
	printf("valor = %s\n", texto);
	return (0);
}
