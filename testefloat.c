/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 20:14:59 by salem             #+#    #+#             */
/*   Updated: 2020/07/08 22:11:28 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long int  pot_b(long int nbr, int base)
{
	long int pot;

	if (nbr <= 0)
		pot = 1;
	else
		pot = base * pot_b(nbr - 1, base);
	return (pot);
}

/*int main(void)
{
	int value = ;
	int i;
	double result;
	double mult;


	i = 22;
	result = 1;
	mult = 2;
	while (i >= 0)
	{
		if ((value & pot_b(i, 2)) == pot_b(i, 2))
		{
			printf("%ld\n", pot_b(i, 2));
			result += 1 / mult;
		}
		mult *= 2;
		i--;
	}
	result *= pot_b(4, 2);
	printf("%f\n", result);
	return (0);
}*/

int main(void)
{
	float value = 123456789.123;
	

	return (0);
}






