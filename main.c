/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 09:16:50 by sfreitas          #+#    #+#             */
/*   Updated: 2020/08/24 22:19:00 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int main ()
{


//	double	ponto = 1;
//	long double	ponto = -56343333340.7855400000456777;
	double	ponto = -0.78045677798744;

// teste com especificador f
	ft_printf("\nvalor f = %f\n", ponto);
	printf("valor f = %f\n", ponto);
	ft_printf("\nvalor f = %.0f\n", ponto);
	printf("valor f = %.0f\n", ponto);
	ft_printf("\nvalor f = %.1f\n", ponto);
	printf("valor f = %.1f\n", ponto);
	ft_printf("\nvalor f = %.2f\n", ponto);
	printf("valor f = %.2f\n", ponto);
	ft_printf("\nvalor f = %.3f\n", ponto);
	printf("valor f = %.3f\n", ponto);
	ft_printf("\nvalor f = %.4f\n", ponto);
	printf("valor f = %.4f\n", ponto);
	ft_printf("\nvalor f = %.5f\n", ponto);
	printf("valor f = %.5f\n", ponto);
	ft_printf("\nvalor f = %.10f\n", ponto);
	printf("valor f = %.10f\n", ponto);


//	 teste com especificador g
	ft_printf("\nvalor g = %g\n", ponto);
	printf("valor g = %g\n", ponto);
	ft_printf("\nvalor g 0 = %.0g\n", ponto);
	printf("valor g 0 = %.0g\n", ponto);
	ft_printf("\nvalor g 1 = %.1g\n", ponto);
	printf("valor g 1 = %.1g\n", ponto);
	ft_printf("\nvalor g 2 = %.2g\n", ponto);
	printf("valor g 2 = %.2g\n", ponto);
	ft_printf("\nvalor g 3 = %.3g\n", ponto);
	printf("valor g 3 = %.3g\n", ponto);
	ft_printf("\nvalor g 4 = %.4g\n", ponto);
	printf("valor g 4 = %.4g\n", ponto);
	ft_printf("\nvalor g 5 = %.15g\n", ponto);
	printf("valor g 5 = %.15g\n", ponto);


// teste com especificador a
	ft_printf("\nvalor e = %e\n", ponto);
	printf("valor e = %e\n", ponto);
	ft_printf("\nvalor e 0 = %.0e\n", ponto);
	printf("valor e 0 = %.0e\n", ponto);
	ft_printf("\nvalor e 1 = %.1e\n", ponto);
	printf("valor e 1 = %.1e\n", ponto);
	ft_printf("\nvalor e 2 = %.2e\n", ponto);
	printf("valor e 2 = %.2e\n", ponto);
	ft_printf("\nvalor e 3 = %.3e\n", ponto);
	printf("valor e 3 = %.3e\n", ponto);
	ft_printf("\nvalor e 4 = %.4e\n", ponto);
	printf("valor e 4 = %.4e\n", ponto);
	ft_printf("\nvalor e 5 = %.5e\n", ponto);
	printf("valor e 5 = %.5e\n", ponto);

	return (0);

}
