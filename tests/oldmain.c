/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oldmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 09:16:50 by sfreitas          #+#    #+#             */
/*   Updated: 2020/12/07 20:40:19 by salem            ###   ########.fr       */
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
	double	ponto = -13.123456789;
	int value = 319827;
	int	*ptr;

	ptr = &value;
ft_printf("teste 42 sp %+d\n", 647);
ft_printf(" --- Return : %d\n\n", ft_printf("%i, %d, %d, %d, %c, %c, %c, %d, %u, %x, %X\n", i, j, k, l, c, c, c, c, j, j, j)); //T2
printf(" --- Return : %d\n\n", printf("%i, %d, %d, %d, %c, %c, %c, %d, %u, %x, %X\n", i, j, k, l, c, c, c, c, j, j, j)); //T2

ft_printf(" --- Return : %d\n", ft_printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d\n", i, j, k, l, m, c, e, d)); //T3
	printf(" --- Return : %d\n\n", printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d\n", i, j, k, l, m, c, e, d)); //T3

ft_printf(" --- Return : %d\n", ft_printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d\n", i, j, k, l, m, c, e, d)); //T4
	printf(" --- Return : %d\n\n", printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d\n", i, j, k, l, m, c, e, d)); //T4

	ft_printf(" --- Return : %d\n", ft_printf("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d\n", i, j, k, l, m, c, e, d)); //T5
	ft_printf("%2i\n", i); //T5
	printf(" --- Return : %d\n\n", printf("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d\n", i, j, k, l, m, c, e, d)); //T5

	ft_printf(" --- Return : %d\n", ft_printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d\n", i, j, k, l, m, c, e, d)); //T6
	printf(" --- Return : %d\n\n", printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d\n", i, j, k, l, m, c, e, d)); //T6

ft_printf(" --- Return : %d\n", ft_printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %.5f\n", i, j, k, l, m, c, e, ponto)); //T6
	printf(" --- Return : %d\n", printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %.5f\n", i, j, k, l, m, c, e, ponto)); //T6

ft_printf(" --- Return : %d\n", ft_printf("%%\n"));
printf(" --- Return : %d\n", printf("%%\n"));


// teste com especificador f
ft_printf(" --- Return : %d\n",ft_printf("valor f = %f\n", ponto));
printf(" --- Return : %d\n",printf("valor f = %f\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor f 0 = %.0f\n", ponto));
printf(" --- Return : %d\n",printf("valor f 0 = %.0f\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor f 1 = %.1f\n", ponto));
printf(" --- Return : %d\n",printf("valor f 1 = %.1f\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor f 2 = %.2f\n", ponto));
printf(" --- Return : %d\n",printf("valor f 2 = %.2f\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor f 3 = %.3f\n", ponto));
printf(" --- Return : %d\n",printf("valor f 3 = %.3f\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor f 4 = %.4f\n", ponto));
printf(" --- Return : %d\n",printf("valor f 4 = %.4f\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor f 5 = %.5f\n", ponto));
printf(" --- Return : %d\n",printf("valor f 5 = %.5f\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor f 10 = %.10f\n", ponto));
printf(" --- Return : %d\n",printf("valor f 10 = %.10f\n", ponto));

printf("\n\nTESTE COM ESPECIFICADOR 'g'\n");

ft_printf(" --- Return : %d\n",ft_printf("valor g = %g\n", ponto));
printf(" --- Return : %d\n",printf("valor g = %g\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor g 0 = %.0g\n", ponto));
printf(" --- Return : %d\n",printf("valor g 0 = %.0g\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor g 1 = %.1g\n", ponto));
printf(" --- Return : %d\n",printf("valor g 1 = %.1g\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor g 2 = %.2g\n", ponto));
printf(" --- Return : %d\n",printf("valor g 2 = %.2g\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor g 3 = %.3g\n", ponto));
printf(" --- Return : %d\n",printf("valor g 3 = %.3g\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor g 4 = %.4g\n", ponto));
printf(" --- Return : %d\n",printf("valor g 4 = %.4g\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor g 5 = %.5g\n", ponto));
printf(" --- Return : %d\n",printf("valor g 5 = %.5g\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor g 10 = %.10g\n", ponto));
printf(" --- Return : %d\n",printf("valor g 10 = %.10g\n", ponto));

printf("\n\nTESTE COM ESPECIFICADOR 'G'\n");

ft_printf(" --- Return : %d\n",ft_printf("valor G  = %G\n", ponto));
printf(" --- Return : %d\n",printf("valor G = %G\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor G 0 = %.0G\n", ponto));
printf(" --- Return : %d\n",printf("valor G 0 = %.0G\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor G 1 = %.1G\n", ponto));
printf(" --- Return : %d\n",printf("valor G 1 = %.1G\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor G 2 = %.2G\n", ponto));
printf(" --- Return : %d\n",printf("valor G 2 = %.2G\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor G 3 = %.3G\n", ponto));
printf(" --- Return : %d\n",printf("valor G 3 = %.3G\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor G 4 = %.4G\n", ponto));
printf(" --- Return : %d\n",printf("valor G 4 = %.4G\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor G 5 = %.5G\n", ponto));
printf(" --- Return : %d\n",printf("valor G 5 = %.5G\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor G 10 = %.10G\n", ponto));
printf(" --- Return : %d\n",printf("valor G 10 = %.10G\n", ponto));

printf("\n\nTESTE COM ESPECIFICADOR 'e'\n");

ft_printf(" --- Return : %d\n",ft_printf("valor e = %e\n", ponto));
printf(" --- Return : %d\n",printf("valor e = %e\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor e 0 = %.0e\n", ponto));
printf(" --- Return : %d\n",printf("valor e 0 = %.0e\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor e 1 = %.1e\n", ponto));
printf(" --- Return : %d\n",printf("valor e 1 = %.1e\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor e 2 = %.2e\n", ponto));
printf(" --- Return : %d\n",printf("valor e 2 = %.2e\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor e 3 = %.3e\n", ponto));
printf(" --- Return : %d\n",printf("valor e 3 = %.3e\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor e 4 = %.4e\n", ponto));
printf(" --- Return : %d\n",printf("valor e 4 = %.4e\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor e 5 = %.5e\n", ponto));
printf(" --- Return : %d\n",printf("valor e 5 = %.5e\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor e 10 = %.10e\n", ponto));
printf(" --- Return : %d\n",printf("valor e 10 = %.10e\n", ponto));

printf("\n\nTESTE COM ESPECIFICADOR 'E'\n");

ft_printf(" --- Return : %d\n",ft_printf("valor E = %E\n", ponto));
printf(" --- Return : %d\n",printf("valor E = %E\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor E 0 = %.0E\n", ponto));
printf(" --- Return : %d\n",printf("valor E 0 = %.0E\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor E 1 = %.1E\n", ponto));
printf(" --- Return : %d\n",printf("valor E 1 = %.1E\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor E 2 = %.2E\n", ponto));
printf(" --- Return : %d\n",printf("valor E 2 = %.2E\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor E 3 = %.3E\n", ponto));
printf(" --- Return : %d\n",printf("valor E 3 = %.3E\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor E 4 = %.4E\n", ponto));
printf(" --- Return : %d\n",printf("valor E 4 = %.4E\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor E 5 = %.5E\n", ponto));
printf(" --- Return : %d\n",printf("valor E 5 = %.5E\n", ponto));
ft_printf(" --- Return : %d\n",ft_printf("valor E 10 = %.10E\n", ponto));
printf(" --- Return : %d\n",printf("valor E 10 = %.10E\n", ponto));
	return (0);

}
