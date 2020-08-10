/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:45:19 by salem             #+#    #+#             */
/*   Updated: 2020/08/09 11:03:36 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_u_itoa_base(unsigned long long int n, char specifier)
{
	char	*ptr;

	ptr = NULL;
	if (specifier == 'u')
		ptr = get_base(n, 10);
	else if (specifier == 'x' || specifier == 'X')
	{
		ptr = get_base(n, 16);
		if (specifier == 'X')
			ptr = str_toupper(ptr);
	}
	else if (specifier == 'o')
		ptr = get_base(n, 8);
	else if (specifier == 'b')
		ptr = get_base(n, 2);
	return(ptr);
}

char	*get_u_base(long long int value, int b)
{
	unsigned long long int	tmp;
	char					*ptr;
	int						d;

	tmp = value;
	ptr = NULL;
	d = 1;
	while (tmp > 0)
	{
		tmp /= b;
		d++;
	}
	ptr = (char*)ft_calloc(sizeof(char), d);
	d = value > 0 ? (d - 2) : (d - 1);
	while (d >= 0 && ptr)
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

	i = 0;
	tmp = (char*)ft_calloc(ft_strlen(source), sizeof(char));
	while (source[i])
	{
		tmp[i] = ft_toupper(source[i]);
		i++;
	}
	free(source);
	return (tmp);
}
