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
	printf("%-5%\n");
	ft_printf("%-5%\n");
	printf("result: %d\n",printf("%7.3s%7.3s\n","hello", "world"));
	ft_printf("result: %d\n",ft_printf("%7.3s%7.3s\n","hello", "world"));
	printf("result: %d\n",printf("%7.3s%3.3s\n","hello", "world"));
	ft_printf("result: %d\n",ft_printf("%7.3s%3.3s\n","hello", "world"));
	printf("result: %d\n",printf("%7.3s\n",NULL));
	ft_printf("result: %d\n",fteprintf("%7.3s\n",NULL));
	return (0);

}
