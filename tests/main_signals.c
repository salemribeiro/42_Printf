/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 21:48:24 by salem             #+#    #+#             */
/*   Updated: 2020/12/03 17:24:29 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <ft_printf.h>

int main()
{
	int	a;
	int *b;

	printf("result: %d\n", printf("%0+3.3i\n", 6983));
	ft_printf("result: %d\n", ft_printf("%0+3.3i\n", 6983));
	printf("result: %d\n", printf("%0+-3.3i\n", -6983));
	ft_printf("result: %d\n", ft_printf("%0+-3.3i\n", -6983));
	printf("result: %d\n", printf("% -7d\n", 33));
	ft_printf("result: %d\n", ft_printf("% -7d\n", 33));
	printf("result: %d\n", printf("% -7d\n", -33));
	ft_printf("result: %d\n", ft_printf("% -7d\n", -33));
	printf("result: %d\n", printf("% +-7d\n", 33));
	ft_printf("result: %d\n", ft_printf("% +-7d\n", 33));
}
