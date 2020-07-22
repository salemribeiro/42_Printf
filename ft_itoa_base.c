/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:45:19 by salem             #+#    #+#             */
/*   Updated: 2020/07/22 00:00:17 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

char	*get_decimal(long long int 




char	*ft_itoa_base(long long int n, char base)
{
	unsigned long long int	value;
	unsigned long long int	eulav;
	int						signal;
	char					ptr;

	eulav = 0;
	signal = n < 0 ? -1 : 1;
	value = (unsigned long long int)(n * signal);
	while (value)
	{
		eulav = (eulav * 10) + (value % 10);
		value /= 10;
	}

	printf("%lld, %lld\n", value, eulav);
	return(NULL);
}

int main()
{
	ft_itoa_base(-0, 'd');

	return (0);
}
