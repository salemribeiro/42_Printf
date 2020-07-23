/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:45:19 by salem             #+#    #+#             */
/*   Updated: 2020/07/22 23:01:00 by sfreitas         ###   ########.fr       */
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
		ptr[digits] = (value % 16) < 10 ? (value % 16) + 48 : (value % 16) + 87;
		value /= 16;
		digits--;
	}
	return (ptr);
}

char	*get_oct(unsigned long long int value)
{
	unsigned long long int	temp;
	char					*ptr;
	int						digits;

	temp = value;
	digits = 1;
	while (temp > 0)
	{
		temp /= 8;
		digits++;
	}
	ptr = (char*)ft_calloc(sizeof(char), digits);
	digits = value > 0 ? (digits - 2) : (digits - 1);
	while (digits >= 0)
	{
		ptr[digits] = (value % 8 + 48);
		value /= 8;
		digits--;
	}
	return (ptr);
}

char	*get_bin(unsigned long long int value)
{
	unsigned long long int	temp;
	char					*ptr;
	int						digits;

	temp = value;
	digits = 1;
	while (temp > 0)
	{
		temp /= 2;
		digits++;
	}
	ptr = (char*)ft_calloc(sizeof(char), digits);
	digits = value > 0 ? (digits - 2) : (digits - 1);
	while (digits >= 0)
	{
		ptr[digits] = (value % 2 + 48);
		value /= 2;
		digits--;
	}
	return (ptr);
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
		ptr = get_oct((unsigned long long int)(n * signal));
	else if (base == 'b')
		ptr = get_bin((unsigned long long int)(n * signal));
	printf("%s\n", ptr);
	return(ptr);
}
