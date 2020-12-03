/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:26:38 by salem             #+#    #+#             */
/*   Updated: 2020/12/03 20:01:51 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_itoa_base(long long int n)
{
	char			*ptr;

	ptr = NULL;
	if (g_opt.specifier == 'd' || g_opt.specifier == 'i')
		ptr = get_base(n, 10);
	return (ptr);
}

char	*get_base(long long int value, int b)
{
	long long int	tmp;
	char			*ptr;
	int				d;

	tmp = value;
	ptr = NULL;
	d = 1;
	while (tmp > 0)
	{
		tmp /= b;
		d++;
	}
	ptr = (char*)ft_calloc(sizeof(char), d + 1);
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
