#include "ft_printf.h"

void	store_dgeneric(long double value)
{
	if (value < 0)
	{
		message_buffer('-');
		value = value * (-1);
	}
	if (g_opt.precision == -2)
			g_opt.precision = 6;
	count_value(value, g_opt.precision);
}

int		count_value(long double value, int precision)
{
	char *ptr;
	int i;

	i = 0;
	if (value <= 1)
	{
		g_opt.precision = g_opt.precision == 0 ? 1 : g_opt.precision;
		store_float(value);
		return(0);
	}
	ptr = ft_u_itoa_base((long long int)value);
	if ((int)ft_strlen(ptr) > precision)
	{
		if (precision > 0)
			g_opt.precision --;
		store_sci(value);
	}
	else
	{
		if (precision > 0)
			g_opt.precision -= (int)ft_strlen(ptr);
		store_float(value);
	}
	free(ptr);
	return(0);
}
