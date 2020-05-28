/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/04/29 22:58:33 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main ()
{
	int		numero = 150;
//	char	*frase = "Salem Freitas Ribeiro";
	float	pnumero = 15.2253336;
//	double	dnumero = 15.2253336;

/*	printf("Número:\t%.10d\n", numero);
	printf("Frase:\t%.10s\n", frase);
	printf("Float:\t%.10f\n", pnumero);
	printf("Double:\t%.10f\n", dnumero);*/
//	tabela_de_tipos();
	ft_printf("salem--%#+-10d 0kk35321121\n", 150);
/*	   printf("salem--%#+- 0kk35321121\n", 150);
	   printf("salem--% 10u kk35321121\n", 150);
	   printf("salem--% 10o kk35321121\n", 150);
	   printf("salem--% 10x kk35321121\n", 150);
	   printf("salem--% 10X kk35321121\n", 150);
	   printf("salem--% 10f kk35321121\n", 150.0f);
	   printf("salem--% 10F kk35321121\n", 150.0f);
	   printf("salem--% 10e kk35321121\n", 150.0f);
	   printf("salem--% 10E kk35321121\n", 150.0f);
	   printf("salem--% 10g kk35321121\n", 150.0f);
	   printf("salem--% 10G kk35321121\n", 150.0f);
	   printf("salem--% 10a kk35321121\n", 150.0f);
	   printf("salem--% 10A kk35321121\n", 150.0f);
	   printf("salem--% 10c kk35321121\n", 'a');
	   printf("salem--% 10s kk35321121\n", "salem");
	   printf("salem--% 10p kk35321121\n", "salem");*/
	   printf("salem--%-% kk35321121\n");
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
