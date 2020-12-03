/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:40:05 by salem             #+#    #+#             */
/*   Updated: 2020/12/03 20:01:07 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_bzero(void *source, size_t len)
{
	unsigned char	*strtemp;
	size_t			i;

	strtemp = source;
	i = 0;
	while (i < len)
	{
		strtemp[i] = '\0';
		i++;
	}
}
