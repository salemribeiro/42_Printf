/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 21:48:24 by salem             #+#    #+#             */
/*   Updated: 2020/11/30 19:42:47 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <ft_printf.h>

int main()
{
	int	a;
	int *b;
	a = -12;
	
	b = &a;
	printf("% .12d\n", a);
	ft_printf("% .12d\n", a);
	printf("% 20.12d\n", a);
	ft_printf("% 20.12d\n", a);
	printf("% .12d\n", a);
	ft_printf("% 0.12d\n", a);




	
	printf("%n", &a);
	printf("\n");
	printf("%d\n", a);
	
	a = -12;
	printf("%d\n", a);

	ft_printf("%n", &a);
	printf("\n");

	printf("%d\n", a);
	/*
	printf("%d\n", *b);
	printf("% 020.12d\n%n", a, b);
	ft_printf("% 020.12d\n%n", a, b);
	printf("%d\n", *b);*/
}
