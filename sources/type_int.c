/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 13:19:01 by salem             #+#    #+#             */
/*   Updated: 2020/08/22 11:52:55 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	store_int(long long int value)
{
	char	*text;
	int		len;

	text = ft_itoa_base(convert_int(value));
	len = ft_strlen(text);
	if (g_opt.precision > 0 && len)
		text = manager_precision(text, g_opt.precision);
	if ((g_opt.flags & PLUS) == PLUS && value >= 0)
		text = ft_strjoin("+", text);
	if (g_opt.width > 0 && len)
		text = manager_width(text, g_opt.width);
	send_buffer(text);
	free(text);
}

void	store_u_int(long long int value)
{
	char	*text;
	int		len;

	text = ft_u_itoa_base(convert_u_int(value));
	len = ft_strlen(text);
	if (g_opt.precision > 0 && ft_strlen(text))
		text = manager_precision(text, g_opt.precision);
	if ((g_opt.flags & PLUS) == PLUS)
		text = ft_strjoin("+", text);
	if (g_opt.width > 0 && len)
		text = manager_width(text, g_opt.width);
	send_buffer(text);
	free (text);
}

long long int	convert_int(long long int value)
{
	if (g_opt.length == LONG)
		value  = (long long int)(long int)value;
	else if (g_opt.length == 0)
		value = (long long int)(int)value;
	else if (g_opt.length == H)
		value = (long long int)(short int)value;
	else if (g_opt.length == HH)
		value = (long long int)(char)value;
	if (value < 0)
	{
		value = value * (-1);
		send_buffer("-");
		g_opt.width = 0;
	}
	return (value);
}

unsigned long long int	convert_u_int(long long int value)
{
	if (g_opt.length == LONG)
		value  = (unsigned long long int)(unsigned long int)value;
	else if (g_opt.length == 0)
		value = (unsigned long long int)(unsigned int)value;
	else if (g_opt.length == H)
		value = (unsigned long long int)(unsigned short int)value;
	else if (g_opt.length == HH)
		value = (unsigned long long int)(unsigned char)value;
	if ((g_opt.flags & SPACE) == SPACE)
		g_opt.flags = g_opt.flags ^ SPACE;
	if ((g_opt.flags & PLUS) == PLUS)
		g_opt.flags = g_opt.flags ^ PLUS;
	if ((g_opt.flags & HASH ) == HASH && g_opt.specifier == 'x')
		send_buffer("0x");
	if ((g_opt.flags & HASH ) == HASH && g_opt.specifier == 'X')
		send_buffer("0X");
	if ((g_opt.flags & HASH ) == HASH && g_opt.specifier == 'o')
		send_buffer("0");
	return (value);
}
