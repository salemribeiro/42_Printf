/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 21:48:24 by salem             #+#    #+#             */
/*   Updated: 2020/11/30 01:48:02 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <ft_printf.h>

int main()
{
	int	a;

	a = -12;
	printf("% .12d\n", a);
	ft_printf("% .12d\n", a);
	printf("% 20.12d\n", a);
	ft_printf("% 20.12d\n", a);
	printf("% .12d\n", a);
	ft_printf("% 0.12d\n", a);
	printf("% 020.12d\n", a);
	ft_printf("% 020.12d\n", a);
}
