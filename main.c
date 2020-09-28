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

	double	ponto = 563340.0000000000456777;

// teste com especificador f
	ft_printf("\nvalor flutuante = %f\n", ponto);
	printf("valor flutuante = %f\n", ponto);
	ft_printf("\nvalor flutuante = %.0f\n", ponto);
	printf("valor flutuante = %.0f\n", ponto);
	ft_printf("\nvalor flutuante = %.1f\n", ponto);
	printf("valor flutuante = %.1f\n", ponto);
	ft_printf("\nvalor flutuante = %.2f\n", ponto);
	printf("valor flutuante = %.2f\n", ponto);
	ft_printf("\nvalor flutuante = %.3f\n", ponto);
	printf("valor flutuante = %.3f\n", ponto);
	ft_printf("\nvalor flutuante = %.4f\n", ponto);
	printf("valor flutuante = %.4f\n", ponto);
	ft_printf("\nvalor flutuante = %.5f\n", ponto);
	printf("valor flutuante = %.5f\n", ponto);
	ft_printf("\nvalor flutuante = %.10f\n", ponto);
	printf("valor flutuante = %.10f\n", ponto);

/*
//	 teste com especificador g
	ft_printf("\nvalor flutuante = %g\n", ponto);
	printf("valor flutuante = %g\n", ponto);
	ft_printf("\nvalor flutuante = %.0g\n", ponto);
	printf("valor flutuante = %.0g\n", ponto);
	ft_printf("\nvalor flutuante = %.1g\n", ponto);
	printf("valor flutuante = %.1g\n", ponto);
	ft_printf("\nvalor flutuante = %.2g\n", ponto);
	printf("valor flutuante = %.2g\n", ponto);
	ft_printf("\nvalor flutuante = %.3g\n", ponto);
	printf("valor flutuante = %.3g\n", ponto);
	ft_printf("\nvalor flutuante = %.4g\n", ponto);
	printf("valor flutuante = %.4g\n", ponto);
	ft_printf("\nvalor flutuante = %.5g\n", ponto);
	printf("valor flutuante = %.5g\n", ponto);
*/

// teste com especificador a
	ft_printf("\nvalor flutuante = %e\n", ponto);
	printf("valor flutuante = %e\n", ponto);
	ft_printf("\nvalor flutuante = %.0e\n", ponto);
	printf("valor flutuante = %.0e\n", ponto);
	ft_printf("\nvalor flutuante = %.1e\n", ponto);
	printf("valor flutuante = %.1e\n", ponto);
	ft_printf("\nvalor flutuante = %.2e\n", ponto);
	printf("valor flutuante = %.2e\n", ponto);
	ft_printf("\nvalor flutuante = %.3e\n", ponto);
	printf("valor flutuante = %.3e\n", ponto);
	ft_printf("\nvalor flutuante = %.4e\n", ponto);
	printf("valor flutuante = %.4e\n", ponto);
	ft_printf("\nvalor flutuante = %.5e\n", ponto);
	printf("valor flutuante = %.5e\n", ponto);

	return (0);

}
