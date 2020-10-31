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
	char	*ptr;
	char	*tmp;
	int 	len;
	int		signal;
	char	caractere;

	signal = value < 0 ? -1 : 1;
	value = value * signal;
	ptr = ft_itoa(value);
	len = ft_strlen(ptr);
	caractere = ' ';
	if (g_opt.precision && g_opt.precision >= len)
	{
		ptr = manager_value(ptr, g_opt.precision, '0');
		if ((g_opt.flags & ZERO) == ZERO)
			g_opt.flags = g_opt.flags ^ ZERO;
	}
	if (signal == -1)
	{
		tmp = ptr;
		ptr = ft_strjoin("-", ptr);
		free(tmp);
	}
	len = ft_strlen(ptr);
	if (g_opt.width > len && g_opt.width)
	{
		if ((g_opt.flags & MINUS) == MINUS)
		{
			tmp = ptr;
			ptr = ft_strjoin(ptr, manager_value(ft_strdup(""),
			g_opt.width - len, caractere));
			free(tmp);
		}
		else
		{
			caractere = (g_opt.flags & ZERO) == ZERO ? '0' : ' ';
			ptr = manager_value(ptr, g_opt.width, caractere);
		}
	}
	send_buffer(ptr);
	free (ptr);
}

/*void	store_int(long long int value)
{
	char	*text;
	int		len;
	text = ft_itoa_base(convert_int(value));
	len = ft_strlen(text);
	if (g_opt.precision > 0 && len)
		text = manager_value(text, g_opt.precision, '0');
	if ((g_opt.flags & PLUS) == PLUS && value >= 0)
		text = ft_strjoin("+", text);
	if (g_opt.width > 0 && len)
	{
		if ((g_opt.flags & ZERO) != ZERO)
			text = manager_value(text, g_opt.width, ' ');
		else
			text = manager_value(text, g_opt.width, '0');
	}
	send_buffer(text);
	free(text);
}*/

void	store_u_int(long long int value)
{
	char	*text;
	int		len;

	text = ft_u_itoa_base(convert_u_int(value));
	len = ft_strlen(text);
	if (g_opt.precision > 0 && ft_strlen(text))
		text = manager_value(text, g_opt.precision, '0');
	if ((g_opt.flags & PLUS) == PLUS)
		text = ft_strjoin("+", text);
	if (g_opt.width > 0 && len)
	{
		if ((g_opt.flags & ZERO) != ZERO)
			text = manager_value(text, g_opt.width, ' ');
		else
			text = manager_value(text, g_opt.width, '0');
	}
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
