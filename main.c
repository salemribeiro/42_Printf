/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 09:16:50 by sfreitas          #+#    #+#             */
/*   Updated: 2020/08/24 22:19:00 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int main ()
{

//	int		a = -4;
//	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
//	int		f = 42;
//	int		g = 25;
//	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
//	char	*n = "abcdefghijklmnop";
//	char	*o = "-a";
//	char	*p = "-12";
//	char	*q = "0";
//	char	*r = "%%";
//	char	*s = "-2147483648";
//	char	*t = "0x12345678";
//	char	*u = "-0";
	float	ponto = -13.999999;


ft_printf(" --- Return : %d\n\n", ft_printf("%i, %d, %d, %d, %c, %c, %c, %d, %u, %x, %X\n", i, j, k, l, c, c, c, c, j, j, j)); //T2

printf(" --- Return : %d\n\n", printf("%i, %d, %d, %d, %c, %c, %c, %d, %u, %x, %X\n", i, j, k, l, c, c, c, c, j, j, j)); //T2


	ft_printf(" --- Return : %d\n", ft_printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d\n", i, j, k, l, m, c, e, d)); //T3
	printf(" --- Return : %d\n\n", printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d\n", i, j, k, l, m, c, e, d)); //T3

ft_printf(" --- Return : %d\n", ft_printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d\n", i, j, k, l, m, c, e, d)); //T4
	printf(" --- Return : %d\n\n", printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d\n", i, j, k, l, m, c, e, d)); //T4
	
	ft_printf(" --- Return : %d\n", ft_printf("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d\n", i, j, k, l, m, c, e, d)); //T5
	printf(" --- Return : %d\n\n", printf("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d\n", i, j, k, l, m, c, e, d)); //T5

	ft_printf(" --- Return : %d\n", ft_printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d\n", i, j, k, l, m, c, e, d)); //T6
	printf(" --- Return : %d\n\n", printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d\n", i, j, k, l, m, c, e, d)); //T6

ft_printf(" --- Return : %d\n", ft_printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %.5f\n", i, j, k, l, m, c, e, ponto)); //T6
	printf(" --- Return : %d\n\n", printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %.5f\n", i, j, k, l, m, c, e, ponto)); //T6

//ft_printf("valor flutuante = %.5Lf\n", ponto);


	return (0);

}
