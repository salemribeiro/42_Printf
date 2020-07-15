/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/07/14 23:05:28 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //remover a linha ao concluir o projeto
#include "ft_printf.h"

int main ()
{
	int		numero = 150;
	double	pnumero = 123.745;

//	tabela_de_tipos();
	ft_printf("salem--%-0.15f 0kk3532| %d |1121\n",pnumero,23);
	   printf("salem--%-.15f 0kk3532| %d |1121\n", pnumero,23);
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
