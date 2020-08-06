/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 21:08:54 by salem             #+#    #+#             */
/*   Updated: 2020/08/04 21:09:02 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	type_table()
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

