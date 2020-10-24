#include "ft_printf.h"

void		store_string(char *text, int width, int precision)
{
	int		i;
	int		len;
	char	*ptr;
	i = 0;
	len = 0;
	if (!text)
		return ;
	ptr = ft_strdup(text);
	len = ft_strlen(ptr);
	if (precision >= 0 && precision <= len)
	{
		while (ptr[i])
		{
			if (i >= precision)
				ptr[i] = '\0';
				i++;
		}
		len = precision;
	}
	if (width > 0 && width > precision)
		send_buffer(manager_width(ft_strdup(" "), width - len));
	send_buffer(ptr);
	free(ptr);
}

unsigned long long int	store_pointer(void *ptr)
{
	unsigned long long int value;

	value = (unsigned long long int)ptr;
	g_opt.specifier = 'x';
	if ((g_opt.flags & HASH) != HASH)
		g_opt.flags = solve_incompatible((g_opt.flags ^ HASH), g_opt.specifier);
	
	return (value);
}

