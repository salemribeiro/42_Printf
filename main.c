/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/06/09 00:03:30 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main ()
{
	int		numero = 150;
	float	pnumero = 15.2253336;

	tabela_de_tipos();
	ft_printf("salem--%-+#0*.*d 0kk3532%-+#099.66d 1121\n", 150,23,30,45);
//	printf("salem--%-+#0ld 0kk35321121\n",150);
	return (0);
}

void	tabela_de_tipos()
{
	printf("---------------------------------------------------------------\n");
	printf("-----------------------TABELA DE TIPOS-------------------------\n");
	printf("---------------------------------------------------------------\n");
	printf("\t\t\tTamanho em\n");
	printf("Tipo\t\t\t   bits\n");
	printf("---------------------------------------------------------------\n");
	printf("char\t\t\t  %lu bits\n", sizeof(char) * 8);
	printf("unsigned char\t\t  %lu bits\n", sizeof(unsigned char) * 8);
	printf("signed char\t\t  %lu bits\n", sizeof(signed char) * 8);
	printf("---------------------------------------------------------------\n");
	printf("int\t\t\t %lu bits\n", sizeof(int) * 8);
	printf("unsigned int\t\t %lu bits\n", sizeof(unsigned int) * 8);
	printf("signed int\t\t %lu bits\n", sizeof(signed int) * 8);
	printf("short int\t\t %lu bits\n", sizeof(short int) * 8);
	printf("unsigned short int\t %lu bits\n", sizeof(unsigned short int) * 8);
	printf("signed short int\t %lu bits\n", sizeof(signed short int) * 8);
	printf("long int\t\t %lu bits\n", sizeof(long int) * 8);
	printf("signed long int\t\t %lu bits\n", sizeof(signed long int) * 8);
	printf("unsigned long int\t %lu bits\n", sizeof(unsigned long int) * 8);
	printf("---------------------------------------------------------------\n");
	printf("long\t\t\t %lu bits\n", sizeof(long) * 8);
	printf("double\t\t\t %lu bits\n", sizeof(double) * 8);
	printf("long double\t\t%lu bits\n", sizeof(long double) * 8);
	printf("---------------------------------------------------------------\n");
}
