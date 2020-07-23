/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:45:19 by salem             #+#    #+#             */
/*   Updated: 2020/07/22 21:52:41 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

char	*get_dec(unsigned long long int value)
{
	unsigned long long int	temp;
	char					*ptr;
	int						digits;

	temp = value;
	digits = 1;
	while (temp > 0)
	{
		temp /= 10;
		digits++;
	}
	ptr = (char*)ft_calloc(sizeof(char), digits);
	digits = value > 0 ? (digits - 2) : (digits - 1);
	while (digits >= 0)
	{
		ptr[digits] = (value % 10 + 48);
		value /= 10;
		digits--;
	}
	return (ptr);
}

char	*get_hex(unsigned long long int value)
{
	unsigned long long int	temp;
	char					*ptr;
	int						digits;

	temp = value;
	digits = 1;
	while (temp > 0)
	{
		temp /= 16;
		digits++;
	}
	ptr = (char*)ft_calloc(sizeof(char), digits);
	digits = value > 0 ? (digits - 2) : (digits - 1);
	while (digits >= 0)
	{
		ptr[digits] = (value % 16) < 10 ? (value % 16 + 48) : (value % 16 + 97);
		value /= 16;
		digits--;
	}
	return (ptr);
}

void	get_oct(unsigned long long int value)
{

}

void	get_bin(unsigned long long int value)
{

}


char	*ft_itoa_base(long long int n, char base)
{
	long long int	temp;
	int				signal;
	char			*ptr;

	temp = n;
	signal = n < 0 ? -1 : 1;
	if (base == 'd')
		ptr = get_dec((unsigned long long int)(n * signal));
	else if (base == 'h')
		ptr = get_hex((unsigned long long int)(n * signal));
	else if (base == 'o')
		get_oct((unsigned long long int)(n * signal));
	else if (base == 'b')
		get_bin((unsigned long long int)(n * signal));
	printf("%s\n", ptr);
	return(NULL);
}

int main()
{
	ft_itoa_base(753, 'h');

	return (0);
}
