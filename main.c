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
	double	ponto = -1.7855400000456777;
//	double	ponto = 0;

// teste com especificador f
	ft_printf("\nvalor f = %f\n", ponto);
	printf("valor f = %a\n", ponto);
	ft_printf("\nvalor f 0 = %.0f\n", ponto);
	printf("valor f 0 = %.0f\n", ponto);
	ft_printf("\nvalor f 1 = %.1f\n", ponto);
	printf("valor f 1 = %.1f\n", ponto);
	ft_printf("\nvalor f 2 = %.2f\n", ponto);
	printf("valor f 2 = %.2f\n", ponto);
	ft_printf("\nvalor f 3 = %.3f\n", ponto);
	printf("valor f 3 = %.3f\n", ponto);
	ft_printf("\nvalor f 4 = %.4f\n", ponto);
	printf("valor f 4 = %.4f\n", ponto);
	ft_printf("\nvalor f 5 = %.5f\n", ponto);
	printf("valor f 5 = %.5f\n", ponto);
	ft_printf("\nvalor f 10 = %.10f\n", ponto);
	printf("valor f 10 = %.10f\n", ponto);


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
	ft_printf("\nvalor g 5 = %.5g\n", ponto);
	printf("valor g 5 = %.5g\n", ponto);
	ft_printf("\nvalor g 10 = %.5g\n", ponto);
	printf("valor g 10 = %.5g\n", ponto);


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
