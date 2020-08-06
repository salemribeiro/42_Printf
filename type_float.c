/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 20:32:31 by salem             #+#    #+#             */
/*   Updated: 2020/08/05 22:27:46 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{

	long double a = 1234.1234567890123456790;
	unsigned long long int esquerda, direita;
	long long int mult;

	direita = 0;
	esquerda = 0;
	printf("Original: %Lf\n", a);
	esquerda = (unsigned long long int) a;
	a = a - (long double)esquerda;

	printf("Esquerda: %lld\n", esquerda);

	while(a > 0)
	{
		a = a * 10;
		direita += (unsigned long long int)a;
		a = a - (long double)(unsigned long long int)a;
		direita = direita * 10;
	}
	printf("direita %lld\n", direita);


	printf("%f\n",(double)a);
	printf("%f\n",(long double)a);

	double b = 1234.1234567890123456790;

	printf("%lf\n", b);
	printf("%lf\n",(double)b);
	printf("%lf\n",(long double)b);
	
	long double c = 1234.1234567890123456790;

	printf("%Lf\n", c);
	printf("%Lf\n",(double)c);
	printf("%Lf\n",(long double)c);
	return(0);
}

