/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/08/04 09:44:31 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>
#include <stdio.h> //remover a linha ao concluir o projeto
#include "ft_printf.h"

int main ()
{
	int	nint = -123454;
	long double pnint = 25;

	ft_printf("\n-----------------INTEIROS COM SINAL-----------------------\n");
	ft_printf("\n*long long int*\n");
	ft_printf("dec %lld hex %llX oct %llo\n", nint, nint, nint);
	   printf("dec %lld hex %llX oct %llo\n", nint, nint, nint);

	ft_printf("\n*long int*\n");
	ft_printf("dec %ld hex %lX oct %lo\n", nint, nint, nint);
	   printf("dec %ld hex %lX oct %lo\n", nint, nint, nint);

	ft_printf("\n*int*\n");
	ft_printf("dec %d hex %X oct %o\n", nint, nint, nint);
	   printf("dec %d hex %X oct %o\n", nint, nint, nint);

	ft_printf("\n*short int*\n");
	ft_printf("dec %hd hex %hX oct %ho\n", nint, nint, nint);
	   printf("dec %hd hex %hX oct %ho\n", nint, nint, nint);

	ft_printf("\n*char int*\n");
	ft_printf("dec %hhd hex %hhX oct %hho\n", nint, nint, nint);
	   printf("dec %hhd hex %hhX oct %hho\n", nint, nint, nint);

	ft_printf("\n----------------INTEIROS SEM SINAL------------------------\n");

	ft_printf("\n*long long int*\n");
	ft_printf("dec %llu hex %llX oct %llo\n", nint, nint, nint);
	   printf("dec %llu hex %llX oct %llo\n", nint, nint, nint);

	ft_printf("\n*long int*\n");
	ft_printf("dec %lu hex %lX oct %lo\n", nint, nint, nint);
	   printf("dec %lu hex %lX oct %lo\n", nint, nint, nint);

	ft_printf("\n*int*\n");
	ft_printf("dec %u hex %X oct %o\n", nint, nint, nint);
	   printf("dec %u hex %X oct %o\n", nint, nint, nint);

	ft_printf("\n*short int*\n");
	ft_printf("dec %hu hex %hX oct %ho\n", nint, nint, nint);
	   printf("dec %hu hex %hX oct %ho\n", nint, nint, nint);

	ft_printf("\n*char int*\n");
	ft_printf("dec %hhu hex %hhX oct %hho\n", nint, nint, nint);
	   printf("dec %hhu hex %hhX oct %hho\n", nint, nint, nint);

	ft_printf("\n------------INTEIROS COM SINAL COM FLAG MAIS--------------\n");
	ft_printf("\n*long long int*\n");
	ft_printf("dec %+lld hex %+llX oct %+llo\n", nint, nint, nint);
	   printf("dec %+lld hex %+llX oct %+llo\n", nint, nint, nint);

	ft_printf("\n*long int*\n");
	ft_printf("dec %+ld hex %+lX oct %+lo\n", nint, nint, nint);
	   printf("dec %+ld hex %+lX oct %+lo\n", nint, nint, nint);

	ft_printf("\n*int*\n");
	ft_printf("dec %+d hex %+X oct %+o\n", nint, nint, nint);
	   printf("dec %+d hex %+X oct %+o\n", nint, nint, nint);

	ft_printf("\n*short int*\n");
	ft_printf("dec %+hd hex %+hX oct %+ho\n", nint, nint, nint);
	   printf("dec %+hd hex %+hX oct %+ho\n", nint, nint, nint);

	ft_printf("\n*char int*\n");
	ft_printf("dec %+hhd hex %+hhX oct %+hho\n", nint, nint, nint);
	   printf("dec %+hhd hex %+hhX oct %+hho\n", nint, nint, nint);

	ft_printf("\n------------INTEIROS SEM SINAL FLAG MAIS------------------\n");

	ft_printf("\n*long long int*\n");
	ft_printf("dec %+llu hex %+llX oct %+llo\n", nint, nint, nint);
	   printf("dec %+llu hex %+llX oct %+llo\n", nint, nint, nint);

	ft_printf("\n*long int*\n");
	ft_printf("dec %+lu hex %+lX oct %+lo\n", nint, nint, nint);
	   printf("dec %+lu hex %+lX oct %+lo\n", nint, nint, nint);

	ft_printf("\n*int*\n");
	ft_printf("dec %+u hex %+X oct %+o\n", nint, nint, nint);
	   printf("dec %+u hex %+X oct %+o\n", nint, nint, nint);

	ft_printf("\n*short int*\n");
	ft_printf("dec %+hu hex %+hX oct %+ho\n", nint, nint, nint);
	   printf("dec %+hu hex %+hX oct %+ho\n", nint, nint, nint);

	ft_printf("\n*char int*\n");
	ft_printf("dec %+hhu hex %+hhX oct %+hho\n", nint, nint, nint);
	   printf("dec %+hhu hex %+hhX oct %+hho\n", nint, nint, nint);

	ft_printf("\n------------INTEIROS COM SINAL COM FLAG MENOS-------------\n");
	ft_printf("\n*long long int*\n");
	ft_printf("dec %-lld hex %-llX oct %-llo\n", nint, nint, nint);
	   printf("dec %-lld hex %-llX oct %-llo\n", nint, nint, nint);

	ft_printf("\n*long int*\n");
	ft_printf("dec %-ld hex %-lX oct %-lo\n", nint, nint, nint);
	   printf("dec %-ld hex %-lX oct %-lo\n", nint, nint, nint);

	ft_printf("\n*int*\n");
	ft_printf("dec %-d hex %-X oct %-o\n", nint, nint, nint);
	   printf("dec %-d hex %-X oct %-o\n", nint, nint, nint);

	ft_printf("\n*short int*\n");
	ft_printf("dec %-hd hex %-hX oct %-ho\n", nint, nint, nint);
	   printf("dec %-hd hex %-hX oct %-ho\n", nint, nint, nint);

	ft_printf("\n*char int*\n");
	ft_printf("dec %-hhd hex %-hhX oct %-hho\n", nint, nint, nint);
	   printf("dec %-hhd hex %-hhX oct %-hho\n", nint, nint, nint);

	ft_printf("\n------------INTEIROS SEM SINAL FLAG MAIS------------------\n");

	ft_printf("\n*long long int*\n");
	ft_printf("dec %-llu hex %-llX oct %-llo\n", nint, nint, nint);
	   printf("dec %-llu hex %-llX oct %-llo\n", nint, nint, nint);

	ft_printf("\n*long int*\n");
	ft_printf("dec %-lu hex %-lX oct %-lo\n", nint, nint, nint);
	   printf("dec %-lu hex %-lX oct %-lo\n", nint, nint, nint);

	ft_printf("\n*int*\n");
	ft_printf("dec %-u hex %-X oct %-o\n", nint, nint, nint);
	   printf("dec %-u hex %-X oct %-o\n", nint, nint, nint);

	ft_printf("\n*short int*\n");
	ft_printf("dec %-hu hex %-hX oct %-ho\n", nint, nint, nint);
	   printf("dec %-hu hex %-hX oct %-ho\n", nint, nint, nint);

	ft_printf("\n*char int*\n");
	ft_printf("dec %-hhu hex %-hhX oct %-hho\n", nint, nint, nint);
	   printf("dec %-hhu hex %-hhX oct %-hho\n", nint, nint, nint);
	tabela_de_tipos();
	return (0);
}

void	tabela_de_tipos()
{
	ft_printf("------------------------------------------------------------\n");
	ft_printf("----------------------TABELA DE TIPOS-----------------------\n");
	ft_printf("------------------------------------------------------------\n");
	ft_printf("\t\t\tTamanho em\n");
	ft_printf("Tipo\t\t\t   bits\n");
	ft_printf("------------------------------------------------------------\n");
	ft_printf("char\t\t\t  %lu bits\n", sizeof(char) * 8);
	ft_printf("unsigned char\t\t  %lu bits\n", sizeof(unsigned char) * 8);
	ft_printf("signed char\t\t  %lu bits\n", sizeof(signed char) * 8);
	ft_printf("------------------------------------------------------------\n");
	ft_printf("int\t\t\t %lu bits\n", sizeof(int) * 8);
	ft_printf("unsigned int\t\t %lu bits\n", sizeof(unsigned int) * 8);
	ft_printf("signed int\t\t %lu bits\n", sizeof(signed int) * 8);
	ft_printf("short int\t\t %lu bits\n", sizeof(short int) * 8);
	ft_printf("unsigned short int\t %lu bits\n", sizeof(unsigned short int) * 8);
	ft_printf("signed short int\t %lu bits\n", sizeof(signed short int) * 8);
	ft_printf("long int\t\t %lu bits\n", sizeof(long int) * 8);
	ft_printf("signed long int\t\t %lu bits\n", sizeof(signed long int) * 8);
	ft_printf("unsigned long int\t %lu bits\n", sizeof(unsigned long int) * 8);
	ft_printf("------------------------------------------------------------\n");
	ft_printf("long\t\t\t %lu bits\n", sizeof(long) * 8);
	ft_printf("double\t\t\t %lu bits\n", sizeof(double) * 8);
	ft_printf("long double\t\t%lu bits\n", sizeof(long double) * 8);
	ft_printf("------------------------------------------------------------\n");
}
