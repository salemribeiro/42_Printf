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


char	*put_signal(char *ptr, char *signal);



void	store_int(long long int value)
{
	char	*ptr;
	char	*tmp;
	int 	len;
	int		signal;
	char	caractere;

	signal = value < 0 ? -1 : 1;
	value = convert_int(value) * signal;
	ptr = ft_itoa(value);
	len = ft_strlen(ptr);
	caractere = ' ';

	if (g_opt.precision && g_opt.precision >= len)
	{
		ptr = manager_value(ptr, g_opt.precision, '0');
		ptr = (signal == -1) ? put_signal(ptr, "-") : ptr;
		signal = 1;
	}
	else if (g_opt.precision && value)
		*ptr= '\0';

	if ((g_opt.flags & ZERO) == ZERO && g_opt.precision > 0)
		g_opt.flags = g_opt.flags ^ ZERO;
	len = ft_strlen(ptr);
	tmp = NULL;

	if ((g_opt.flags & MINUS) == MINUS)
	{
		if (signal == 1)
			ptr = ft_strjoin(ptr, manager_value(ft_strdup(""),
			g_opt.width - len, caractere));
		else
		{
			ptr = ft_strjoin(ptr, manager_value(ft_strdup(""),
			g_opt.width - len - 1, caractere));
			tmp = ptr;
			ptr = ft_strjoin("-", ptr);
		}
	}
	else
	{
		if ((g_opt.flags & ZERO) == ZERO && g_opt.precision != 0)
		{
			g_opt.width = (signal == -1 && g_opt.width > 0) ?
			g_opt.width -1 : g_opt.width;
			ptr = manager_value(ptr, g_opt.width, '0');
			if (signal == -1)
			{
				tmp = ptr;
				ptr = ft_strjoin("-", ptr);
			}
		}
		else
		{
			if(ptr[0] != '-' && signal == -1)
			{
				tmp = ptr;
				ptr = ft_strjoin("-", ptr);
			}
			ptr = manager_value(ptr, g_opt.width, ' ');
		}
	}
	if (tmp)
		free(tmp);
	send_buffer(ptr);
	free (ptr);
}


char	*put_signal(char *ptr, char *signal)
{
	char *tmp;

	tmp = ptr;
	ptr = ft_strjoin(signal, ptr);
	free(tmp);
	return (ptr);
}





char	*put_hex(char *ptr)
{
	char *tmp;

	tmp = NULL;
	if (g_opt.specifier == 'x')
	{
		tmp = ptr;
		ptr = ft_strjoin("0x", ptr);
	}
	else if (g_opt.specifier == 'X')
	{
		tmp = ptr;
		ptr = ft_strjoin("0X", ptr);
	}
	else if (g_opt.specifier == 'o')
	{
		tmp = ptr;
		ptr = ft_strjoin("0", ptr);
	}
	if (tmp)
		free(tmp);
	return (ptr);
}

void	store_u_int(long long int value)
{
	char	*ptr;
	int		len;

	value = convert_u_int(value);
	ptr = ft_u_itoa_base(value);
	len = ft_strlen(ptr);
	if (g_opt.precision > 0 && g_opt.precision > len)
		ptr = manager_value(ptr, g_opt.precision, '0');
	else if (g_opt.precision == 0  && value == 0)
	{
		free (ptr);
		ptr = ft_strdup("");
	}
	if ((g_opt.flags & ZERO) == ZERO && g_opt.precision > 0)
		g_opt.flags = g_opt.flags ^ ZERO;
	len = ft_strlen(ptr);
	if ((g_opt.flags & MINUS) == MINUS)
	{
		ptr = (g_opt.flags & HASH) == HASH ? put_hex(ptr) : ptr;
		len = ft_strlen(ptr);
		ptr = ft_strjoin(ptr, manager_value(ft_strdup(""),
		g_opt.width - len, ' '));
	}
	else
	{
		if ((g_opt.flags & ZERO) == ZERO && g_opt.precision != 0)
		{
			ptr = manager_value(ptr, g_opt.width, '0');
			ptr = (g_opt.flags & HASH) == HASH ? put_hex(ptr) : ptr;
		}
		else
		{
			ptr = (g_opt.flags & HASH) == HASH ? put_hex(ptr) : ptr;
			ptr = manager_value(ptr, g_opt.width, ' ');
		}
	}
	send_buffer(ptr);
	free (ptr);
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
	return (value);
}
