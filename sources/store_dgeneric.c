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
	int j;
	long long int mult;
	long long int eint;

	i = 0;
	mult = 1;
	eint = (long long int)value;
	ptr = ft_u_itoa_base(eint);
	j = ft_strlen(ptr);
	free(ptr);
	if (j > precision)
	{
		if (precision > 0)
			g_opt.precision --;
		g_opt.specifier = g_opt.specifier == 'g' ? 'e' : 'E';
		store_sci(value);
	}
	else
	{
		if (precision > 0)
			g_opt.precision -= j;
		g_opt.specifier = g_opt.specifier == 'g' ? 'f' : 'F';
		store_float(value);
	}
	return(1);
}
