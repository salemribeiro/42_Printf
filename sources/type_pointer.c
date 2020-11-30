/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:59:10 by salem             #+#    #+#             */
/*   Updated: 2020/11/30 02:46:51 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			cut_string(char *ptr, int precision)
{
	int len;
	int i;

	len = ft_strlen(ptr);
	i = 0;
	if (precision >= 0 && precision <= len)
	{
		while (ptr[i])
		{
			if (i >= precision)
				ptr[i] = '\0';
			i++;
		}
	}
	len = ft_strlen(ptr);
	return (len);
}

void		store_string(char *text, int width, int precision, char flags)
{
	int		len;
	char	*ptr;
	char	*tmp;

	len = 0;
	tmp = NULL;
	if (!text)
		ptr = ft_strdup("(null)");
	else
		ptr = ft_strdup(text);
	len = cut_string(ptr, precision);
	if ((flags & ZERO) != ZERO)
		tmp = manager_value(ft_strdup(""), width - len, ' ');
	else
		tmp = manager_value(ft_strdup(""), width - len, '0');
	if ((flags & MINUS) != MINUS && width > len)
		send_buffer(tmp);
	send_buffer(ptr);
	if ((flags & MINUS) == MINUS && width > len)
		send_buffer(tmp);
	if (tmp)
		free(tmp);
	free(ptr);
}

t_ulli		store_pointer(void *ptr)
{
	t_ulli		value;

	value = (t_ulli)ptr;
	g_opt.specifier = 'x';
	if ((g_opt.flags & HASH) != HASH)
		g_opt.flags = solve_incompatible((g_opt.flags ^ HASH), g_opt.specifier);
	return (value);
}
/*
void	store_n(va_list item)
{
	if (g_opt.length == H)
		va_arg(item, char*) 
	else if (g_opt.length == HH)
	else if (g_opt.length == LONG)
	else if (g_opt.length == LL)
	else

}
*/



