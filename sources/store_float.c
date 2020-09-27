/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 19:26:26 by sfreitas          #+#    #+#             */
/*   Updated: 2020/09/07 20:32:28 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Funcao recebe com parametro um long double, faz o tratamento do sinal e
**   precisao padrao e envia para as funcoes resposaveis por tratar
**   o arredondamento.
*/

void	store_float(long double value)
{
	if (value < 0)
	{
		message_buffer('-');
		value = value * (-1);
	}
	if (g_opt.precision == -2)
	{
		if (g_opt.specifier == 'g' || g_opt.specifier == 'G')
			g_opt.precision = 4;
		else
			g_opt.precision = 6;
	}
	convert_char(value, g_opt.precision);
}


int		count_digits(long long int a, long long int b)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (a > 0)
	{
		a = a / 10;
		i++;
	}
	while (b > 0)
	{
		b = b / 10;
		j++;
	}
	return (j - i);
}



int		convert_double(long double value, int precision)
{
	long long int	eint;
	long long int	dint;
	long long int	hint;
	long long int	mult;
	long long int	i;
	
	mult = 1;
	i = 0;
	while (precision > i++)
		mult *= 10;
	eint = (long long int)value;
	value = (value - (long double)eint) * mult;
	dint = (long long int)value;
	value = (value - (long double)dint) * 10;
	hint = dint;
	if ((long long int)value >= 5)
		dint++;
	if (count_digits(hint, dint))
	{
		eint++;
		dint = 0;
	}
	join_number(eint, dint, precision);
	return (0);
}

int		join_number(long long int eint, long long dint, int precision)
{
	int i;

	i = 0;
	if (g_opt.specifier == 'f' || g_opt.specifier == 'F')
	{
		send_buffer(ft_itoa(eint));
		if (dint && precision > 0)
		{
			message_buffer('.');
			send_buffer(ft_itoa(dint));
		}
		else if (!dint && precision > 0)
		{
			message_buffer('.');
			while (i < precision)
			{
				message_buffer('0');
				i++;
			}
		}
	}
	return (0);
}





/*
** Funcao recebe como parametro um long double e um inteiro.
**  trata o valor de double e o envia para um array de char, esse array e
**  enviado para a funcao responsavel por arredondar os valores.
*/

void	convert_char(long double value, int precision)
{
	long long int	v_int;
	long double		v_doub;
	char			*c_number;
	int				i;
	int				flag;

	i = 0;
	v_int = (long long int)value;
	v_doub = value - (long double)(long long int)value;
	c_number = ft_calloc(precision + 2, sizeof(char));
	while (i <= precision)
	{
		v_doub = v_doub * 10;
		c_number[i] = (char)v_doub;
		v_doub = v_doub - (long double)c_number[i];
		i++;
	}
	flag = round_number(c_number, precision);
	if (flag)
		v_int++;
	sum_one(c_number, precision);
	send_buffer(ft_itoa(v_int));
	if ((g_opt.specifier == 'g' && !flag) || (g_opt.specifier =='G' && !flag))
	{
		message_buffer('.');
		send_buffer(c_number);
	}
}

/*
** Funcao recebe um array de char e um inteiro indicando a precisao
**  se o numero for maior ou igual a 5 o numero anterior ganha uma unidade
*/

char	round_number(char *value, int precision)
{
	int i;

	i = precision;
	if (value[i] >= 0 && value[i] < 5)
		value[i] = '\0';
	while ((i >= 0 && value[i] >= 5) || value[i] == -1)
	{
		if ((value[i] >= 5 && i > 0) || (value[i] == -1 && i > 0))
		{
			if (value[i - 1] < 9)
			{
				value[i - 1]++;
				return (0);
			}
			else if (value[i - 1] == 9)
			{
				value[i - 1] = -1;
			}
		}
		else if ((value[i] >= 5 && i == 0) || (value[i] == -1 && i ==0))
			return (1);
		i--;
	}
	return (0);
}

/*
** Funcao responsavel por tratar os valores inteiros criando correspondencias
**   com a tabela ascii, faz isso incrementando 48 ao valor encontrado.
*/

char	*sum_one(char *value, int precision)
{
	int i;

	i = 0;
	while (i < precision)
	{
		if (value[i] == -1)
			value[i]++;
		value[i] += 48;
		i++;
	}
	i++;
	while (i >= 0)
	{
		if (value[i] == 48)
			value[i] = '\0';
		i--;
	}
	return value;
}
