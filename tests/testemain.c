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
	printf("%d\n", printf("%5%\n"));
	ft_printf("%d\n", ft_printf("%5%\n"));
	printf("%d\n", printf("%-5%\n"));
	ft_printf("%d\n", ft_printf("%-5%\n"));
	printf("%d\n", printf("%05%\n"));
	ft_printf("%d\n", ft_printf("%05%\n"));
	printf("%d\n", printf("%-05%\n"));
	ft_printf("%d\n", ft_printf("%-05%\n"));
	printf("result: %d\n",printf("%-7.3s\n",""));
	ft_printf("result: %d\n",ft_printf("%-7.3s\n",""));
	printf("result: %d\n",printf("%7.3s%7.3s\n","hello", "world"));
	ft_printf("result: %d\n",ft_printf("%7.3s%7.3s\n","hello", "world"));
	printf("result: %d\n",printf("%-7.3s%3.3s\n","hello", "world"));
	ft_printf("result: %d\n",ft_printf("%-7.3s%3.3s\n","hello", "world"));
	printf("result: %d\n",printf("%7.3s%3.3s\n","hello", "world"));
	ft_printf("result: %d\n",ft_printf("%7.3s%3.3s\n","hello", "world"));
	printf("result: %d\n",printf("%6.6s\n",""));
	ft_printf("result: %d\n",ft_printf("%6.6s\n",""));
	return (0);

}
