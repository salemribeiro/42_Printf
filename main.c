/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/07/31 00:18:30 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>
#include <stdio.h> //remover a linha ao concluir o projeto
#include "ft_printf.h"

int main ()
{
	int	numero = 123454;
	long double pnumero = 25;

//	tabela_de_tipos();
	ft_printf("dec %hd hex %hX oct %ho\n", numero, numero, numero);
	   printf("dec %hd hex %hX oct %ho\n", numero, numero, numero);

	ft_printf("hex %x\n", numero);
	   printf("hex %x\n", numero);

	ft_printf("oct %o\n", numero);
	   printf("oct %o\n", numero);
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
