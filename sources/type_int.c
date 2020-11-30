/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:55:10 by salem             #+#    #+#             */
/*   Updated: 2020/11/30 02:17:04 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*manager_precision(char *ptr, t_lli value, int *signal, int len)
{
	char	*tmp;

	if (g_opt.precision && g_opt.precision >= len)
	{
		ptr = manager_value(ptr, g_opt.precision, '0');
		if (*signal == -1)
		{
			tmp = ptr;
			ptr = ft_strjoin("-", ptr);
			*signal = 1;
			free(tmp);
		}
		else
			ptr = solve_signal(ptr, *signal);
	}
	else if (g_opt.precision == 0 && value == 0)
	{
		free(ptr);
		ptr = ft_strdup("");
	}
	return (ptr);
}

static char	*manager_width(char *ptr, int *signal)
{
	if ((g_opt.flags & ZERO) == ZERO && g_opt.precision != 0)
	{
		g_opt.width = ((*signal == -1 || (g_opt.flags & PLUS) == PLUS ||
		(g_opt.flags & SPACE) == SPACE) && g_opt.width > 0) ?
		g_opt.width - 1 : g_opt.width;
		ptr = manager_value(ptr, g_opt.width, '0');
		ptr = solve_signal(ptr, *signal);
	}
	else
	{
		if (ptr[0] != '-' && *signal == -1)
			ptr = solve_signal(ptr, *signal);
		else if (ptr[0] != '-')
			ptr = solve_signal(ptr, *signal);
		ptr = manager_value(ptr, g_opt.width, ' ');
	}
	return (ptr);
}

static char	*manager_minus(char *ptr, char **tmp, int *signal, char *caractere)
{
	int len;

	len = ft_strlen(ptr);
	if ((g_opt.flags & MINUS) == MINUS)
	{
		if (*signal == 1)
			ptr = ft_strjoin(ptr, manager_value(ft_strdup(""),
			g_opt.width - len, *caractere));
		else
		{
			ptr = ft_strjoin(ptr, manager_value(ft_strdup(""),
			g_opt.width - len - 1, *caractere));
			*tmp = ptr;
			ptr = ft_strjoin("-", ptr);
		}
	}
	else
		ptr = manager_width(ptr, signal);
	return (ptr);
}

void		store_int(long long int value)
{
	char	*ptr;
	char	*tmp;
	int		len;
	int		signal;
	char	caractere;

	signal = value < 0 ? -1 : 1;
	value = convert_int(value) * signal;
	ptr = ft_itoa(value);
	len = ft_strlen(ptr);
	caractere = ' ';
	ptr = manager_precision(ptr, value, &signal, len);
	if ((g_opt.flags & ZERO) == ZERO && g_opt.precision > 0)
		g_opt.flags = g_opt.flags ^ ZERO;
	len = ft_strlen(ptr);
	tmp = NULL;
	ptr = manager_minus(ptr, &tmp, &signal, &caractere);
	if (tmp)
		free(tmp);
	send_buffer(ptr);
	free(ptr);
}

t_lli		convert_int(long long int value)
{
	if (g_opt.length == LONG)
		value = (long long int)(long int)value;
	else if (g_opt.length == 0)
		value = (long long int)(int)value;
	else if (g_opt.length == H)
		value = (long long int)(short int)value;
	else if (g_opt.length == HH)
		value = (long long int)(char)value;
	return (value);
}
