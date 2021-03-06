/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testemain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 09:16:50 by sfreitas          #+#    #+#             */
/*   Updated: 2020/11/28 11:03:21 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdint.h>
int main ()
{
	int		i;
	int		a;
	char valor[4];
	valor[0] = 0xc5;
	valor[1] = 0x93;
	valor[2] = 0xc3;
	valor[3] = '\0';
	
	

	i = 20;
	a = 12;
	printf("%d\n", printf("%"));
	ft_printf("%d\n", ft_printf("%"));
	printf("%d\n", printf("%5%\n"));
	ft_printf("%d\n", ft_printf("%5%\n"));
	printf("%d\n", printf("%-5%\n"));
	ft_printf("%d\n", ft_printf("%-5%\n"));
	printf("%d\n", printf("%05%\n"));
	ft_printf("%d\n", ft_printf("%05%\n"));
	printf("%d\n", printf("%-05%\n"));
	ft_printf("%d\n", ft_printf("%-05%\n"));
	printf("result: %d\n",printf("%-7.3s\n",""));
	ft_printf("result: %d\n",ft_printf("%-7.3s\n",""));
	printf("result: %d\n",printf("%7.3s%7.3s\n","hello", "world"));
	ft_printf("result: %d\n",ft_printf("%7.3s%7.3s\n","hello", "world"));
	printf("result: %d\n",printf("%-7.3s%3.3s\n","hello", "world"));
	ft_printf("result: %d\n",ft_printf("%-7.3s%3.3s\n","hello", "world"));
	printf("result: %d\n",printf("%7.3s%3.3s\n","hello", "world"));
	ft_printf("result: %d\n",ft_printf("%7.3s%3.3s\n","hello", "world"));
	printf("result: %d\n",printf("%6.6s\n",""));
	ft_printf("result: %d\n",ft_printf("%6.6s\n",""));
	printf("result: %d\n",printf("%07.3s%3.3s\n","hello", "world"));
	ft_printf("result: %d\n",ft_printf("%07.3s%3.3s\n","hello", "world"));
	printf("result: %d\n",printf("%c",0));
	ft_printf("result: %d\n",ft_printf("%c",0));
	printf("result: %d\n",printf("%%04i 42 == |%04i\x0a\n",42));
	ft_printf("result: %d\n",ft_printf("%%04i 42 == |%04i\x0a\n",42));
	printf("result: %d\n",printf("%7i\n", -14));
	ft_printf("result: %d\n",ft_printf("%7i\n", -14));
	printf("result: %d\n",printf("teste %+10d\n", -44));
	ft_printf("result: %d\n",ft_printf("teste %+10d\n", -44));
	printf("result: %d\n",printf("teste %-17ofim\n",10733));
	ft_printf("result: %d\n",ft_printf("teste %-17ofim\n",10733));
	printf("result: %d\n",printf("teste %-5p fim\n",i));
	ft_printf("result: %d\n",ft_printf("teste %-5p fim\n",i));
	printf("result: %d\n",printf("teste %.*ifim\n", 10, -3));
	ft_printf("result: %d\n",ft_printf("teste %.*i fim\n",10, -3));
	printf("result: %d\n",printf("teste %5c fim\n", INT8_MAX));
	ft_printf("result: %d\n",ft_printf("teste %5c fim\n", INT8_MAX));
	ft_printf("result: %d\n",ft_printf("teste %-5p fim\n", 10, i));
	printf("result: %d\n",printf("teste %.d fim\n", 10, i));
	ft_printf("result: %d\n",ft_printf("teste %.d fim\n", 10, i));
	printf("result: %d\n",printf("%-*.*s\n", -7, -3, "yolo"));
	ft_printf("result: %d\n",ft_printf("%-*.*s\n", -7, -3, "yolo"));
	printf("result: %d\n",printf("%0*.*x\n", 1, 0, 0));
	ft_printf("result: %d\n",ft_printf("%0*.*x\n", 1, 0, 0));
	printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL);
	ft_printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL);
	printf("%.s\n", NULL);
	ft_printf("%.s\n", NULL);
	ft_printf(" --- Return : %d\n", ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c", -12, -1, -255, a, -12,     a, -1, a, -255));


	printf("result: %d\n",printf("teste %s\n", valor));
	ft_printf("result: %d\n",ft_printf("teste %s\n", valor));
	return (0);

}
