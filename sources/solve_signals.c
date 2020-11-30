/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 22:17:18 by salem             #+#    #+#             */
/*   Updated: 2020/11/29 23:26:17 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*solve_signal(char *ptr)
{
	char *tmp;

	tmp = ptr;
	if ((g_opt.flags & PLUS) == PLUS)
	{
		ptr = ft_strjoin("+", ptr);
		free(tmp);
	}
	else if ((g_opt.flags & SPACE) == SPACE)
	{
		ptr = ft_strjoin(" ", ptr);
		free(tmp);
	}
	return (ptr);
}
