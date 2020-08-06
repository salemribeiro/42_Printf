/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 21:06:30 by salem             #+#    #+#             */
/*   Updated: 2020/08/04 21:07:51 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	test_int_only_signal()
{
	int	nint = -123454;

	ft_printf("\n-----------------INTEIROS COM SINAL-----------------------\n");
	ft_printf("\n*long long int*\n");
	ft_printf("dec %lld hex %llX oct %llo\n", nint, nint, nint);
	   printf("dec %lld hex %llX oct %llo\n", nint, nint, nint);

	ft_printf("\n*long int*\n");
	ft_printf("dec %ld hex %lX oct %lo\n", nint, nint, nint);
	   printf("dec %ld hex %lX oct %lo\n", nint, nint, nint);

	ft_printf("\n*int*\n");
	ft_printf("dec %d hex %X oct %o\n", nint, nint, nint);
	   printf("dec %d hex %X oct %o\n", nint, nint, nint);

	ft_printf("\n*short int*\n");
	ft_printf("dec %hd hex %hX oct %ho\n", nint, nint, nint);
	   printf("dec %hd hex %hX oct %ho\n", nint, nint, nint);

	ft_printf("\n*char int*\n");
	ft_printf("dec %hhd hex %hhX oct %hho\n", nint, nint, nint);
	   printf("dec %hhd hex %hhX oct %hho\n", nint, nint, nint);

	ft_printf("\n----------------INTEIROS SEM SINAL------------------------\n");

	ft_printf("\n*long long int*\n");
	ft_printf("dec %llu hex %llX oct %llo\n", nint, nint, nint);
	   printf("dec %llu hex %llX oct %llo\n", nint, nint, nint);

	ft_printf("\n*long int*\n");
	ft_printf("dec %lu hex %lX oct %lo\n", nint, nint, nint);
	   printf("dec %lu hex %lX oct %lo\n", nint, nint, nint);

	ft_printf("\n*int*\n");
	ft_printf("dec %u hex %X oct %o\n", nint, nint, nint);
	   printf("dec %u hex %X oct %o\n", nint, nint, nint);

	ft_printf("\n*short int*\n");
	ft_printf("dec %hu hex %hX oct %ho\n", nint, nint, nint);
	   printf("dec %hu hex %hX oct %ho\n", nint, nint, nint);

	ft_printf("\n*char int*\n");
	ft_printf("dec %hhu hex %hhX oct %hho\n", nint, nint, nint);
	   printf("dec %hhu hex %hhX oct %hho\n", nint, nint, nint);

	ft_printf("\n------------INTEIROS COM SINAL COM FLAG MAIS--------------\n");
	ft_printf("\n*long long int*\n");
	ft_printf("dec %+lld hex %+llX oct %+llo\n", nint, nint, nint);
	   printf("dec %+lld hex %+llX oct %+llo\n", nint, nint, nint);

	ft_printf("\n*long int*\n");
	ft_printf("dec %+ld hex %+lX oct %+lo\n", nint, nint, nint);
	   printf("dec %+ld hex %+lX oct %+lo\n", nint, nint, nint);

	ft_printf("\n*int*\n");
	ft_printf("dec %+d hex %+X oct %+o\n", nint, nint, nint);
	   printf("dec %+d hex %+X oct %+o\n", nint, nint, nint);

	ft_printf("\n*short int*\n");
	ft_printf("dec %+hd hex %+hX oct %+ho\n", nint, nint, nint);
	   printf("dec %+hd hex %+hX oct %+ho\n", nint, nint, nint);

	ft_printf("\n*char int*\n");
	ft_printf("dec %+hhd hex %+hhX oct %+hho\n", nint, nint, nint);
	   printf("dec %+hhd hex %+hhX oct %+hho\n", nint, nint, nint);

	ft_printf("\n------------INTEIROS SEM SINAL FLAG MAIS------------------\n");

	ft_printf("\n*long long int*\n");
	ft_printf("dec %+llu hex %+llX oct %+llo\n", nint, nint, nint);
	   printf("dec %+llu hex %+llX oct %+llo\n", nint, nint, nint);

	ft_printf("\n*long int*\n");
	ft_printf("dec %+lu hex %+lX oct %+lo\n", nint, nint, nint);
	   printf("dec %+lu hex %+lX oct %+lo\n", nint, nint, nint);

	ft_printf("\n*int*\n");
	ft_printf("dec %+u hex %+X oct %+o\n", nint, nint, nint);
	   printf("dec %+u hex %+X oct %+o\n", nint, nint, nint);

	ft_printf("\n*short int*\n");
	ft_printf("dec %+hu hex %+hX oct %+ho\n", nint, nint, nint);
	   printf("dec %+hu hex %+hX oct %+ho\n", nint, nint, nint);

	ft_printf("\n*char int*\n");
	ft_printf("dec %+hhu hex %+hhX oct %+hho\n", nint, nint, nint);
	   printf("dec %+hhu hex %+hhX oct %+hho\n", nint, nint, nint);

	ft_printf("\n------------INTEIROS COM SINAL COM FLAG MENOS-------------\n");
	ft_printf("\n*long long int*\n");
	ft_printf("dec %-lld hex %-llX oct %-llo\n", nint, nint, nint);
	   printf("dec %-lld hex %-llX oct %-llo\n", nint, nint, nint);

	ft_printf("\n*long int*\n");
	ft_printf("dec %-ld hex %-lX oct %-lo\n", nint, nint, nint);
	   printf("dec %-ld hex %-lX oct %-lo\n", nint, nint, nint);

	ft_printf("\n*int*\n");
	ft_printf("dec %-d hex %-X oct %-o\n", nint, nint, nint);
	   printf("dec %-d hex %-X oct %-o\n", nint, nint, nint);

	ft_printf("\n*short int*\n");
	ft_printf("dec %-hd hex %-hX oct %-ho\n", nint, nint, nint);
	   printf("dec %-hd hex %-hX oct %-ho\n", nint, nint, nint);

	ft_printf("\n*char int*\n");
	ft_printf("dec %-hhd hex %-hhX oct %-hho\n", nint, nint, nint);
	   printf("dec %-hhd hex %-hhX oct %-hho\n", nint, nint, nint);

	ft_printf("\n------------INTEIROS SEM SINAL FLAG MENOS------------------\n");

	ft_printf("\n*long long int*\n");
	ft_printf("dec %-llu hex %-llX oct %-llo\n", nint, nint, nint);
	   printf("dec %-llu hex %-llX oct %-llo\n", nint, nint, nint);

	ft_printf("\n*long int*\n");
	ft_printf("dec %-lu hex %-lX oct %-lo\n", nint, nint, nint);
	   printf("dec %-lu hex %-lX oct %-lo\n", nint, nint, nint);

	ft_printf("\n*int*\n");
	ft_printf("dec %-u hex %-X oct %-o\n", nint, nint, nint);
	   printf("dec %-u hex %-X oct %-o\n", nint, nint, nint);

	ft_printf("\n*short int*\n");
	ft_printf("dec %-hu hex %-hX oct %-ho\n", nint, nint, nint);
	   printf("dec %-hu hex %-hX oct %-ho\n", nint, nint, nint);

	ft_printf("\n*char int*\n");
	ft_printf("dec %-hhu hex %-hhX oct %-hho\n", nint, nint, nint);
	   printf("dec %-hhu hex %-hhX oct %-hho\n", nint, nint, nint);
}

