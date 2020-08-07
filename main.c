/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 09:16:50 by sfreitas          #+#    #+#             */
/*   Updated: 2020/08/06 22:07:35 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main ()
{
	int	nint = -123454;
	long double pnint = 25;

//	type_table();
//	test_int_only_signal();
//	test_int_signal_with_space();
//	test_int_signal_with_hash();
	ft_printf("Caractere:\n");
	ft_printf("ft: %d\n",ft_printf("1 - %c, 2 - %c 12345%c6789\n", 'A', 'B','\0'));
	printf("ft: %d\n",printf("1 - %c, 2 - %c 12345%c6789\n", 'A', 'B','\0'));
	ft_printf("String\n");
	ft_printf("ft: %d\n",ft_printf("texto = %s\n", "salem.ribeiro@gepro.eng.br"));
	printf("pt: %d\n",printf("texto = %s\n", "salem.ribeiro@gepro.eng.br"));
	return (0);
}
