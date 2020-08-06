/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 09:16:50 by sfreitas          #+#    #+#             */
/*   Updated: 2020/08/06 09:16:56 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "salem_printflover.h"

int main ()
{
	int	nint = -123454;
	long double pnint = 25;

	type_table();
	test_int_only_signal();
	test_int_signal_with_space();
	test_int_signal_with_hash();
/*
	ft_printf("% d salem\n",1234);
	printf("% d salem\n",1234);
*/
	return (0);
}
