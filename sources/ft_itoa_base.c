/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:45:19 by salem             #+#    #+#             */
/*   Updated: 2020/07/26 23:48:56 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(long long int n, char specifier)
{
	long long int	tmp;
	int				signal;
	char			*ptr;

	tmp = n;
	signal = n < 0 ? -1 : 1;
	if (specifier == 'd' || specifier == 'i')
		ptr = get_base((unsigned long long int)(n * signal), 10);
	else if (specifier == 'x' || specifier == 'X')
	{
		ptr = get_base((unsigned long long int)(n * signal), 16);
		if (specifier == 'X')
			ptr = str_toupper(ptr);
	}
	else if (specifier == 'o')
		ptr = get_base((unsigned long long int)(n * signal), 8);
	else if (specifier == 'b')
		ptr = get_base((unsigned long long int)(n * signal), 2);
	return(ptr);
}

char	*get_base(unsigned long long int value, int b)
{
	unsigned long long int	tmp;
	char					*ptr;
	int						d;

	tmp = value;
	d = 1;
	while (tmp > 0)
	{
		tmp /= b;
		d++;
	}
	ptr = (char*)ft_calloc(sizeof(char), d);
	d = value > 0 ? (d - 2) : (d - 1);
	while (d >= 0)
	{
		if (b == 16)
			ptr[d] = (value % b) < 10 ? (value % b) + 48 : (value % b) + 87;
		else
			ptr[d] = (value % b + 48);
		value /= b;
		d--;
	}
	return (ptr);
}

char	*str_toupper(char *source)
{
	char	*tmp;
	int		 i;

	tmp = source;
	i = 0;
	while (tmp[i])
	{
		tmp[i] = ft_toupper(tmp[i]);
		i++;
	}
	free(source);
	return (tmp);
}
