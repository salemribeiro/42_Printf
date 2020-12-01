/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_signals_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 22:28:54 by salem             #+#    #+#             */
/*   Updated: 2020/11/30 22:29:12 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*solve_signal(char *ptr, int signal)
{
	char *tmp;

	tmp = ptr;
	if (signal == -1)
	{
		ptr = ft_strjoin("-", ptr);
		free(tmp);
	}
	else if ((g_opt.flags & PLUS) == PLUS && ptr[0] != '+' && ptr[0] != ' ')
	{
		ptr = ft_strjoin("+", ptr);
		free(tmp);
	}
	else if ((g_opt.flags & SPACE) == SPACE && ptr[0] != '+' && ptr[0] != ' ')
	{
		ptr = ft_strjoin(" ", ptr);
		free(tmp);
	}
	return (ptr);
}
