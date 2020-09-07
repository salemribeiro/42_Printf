#include "ft_printf.h"

void		store_string(char *text)
{
	send_buffer(text);
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

