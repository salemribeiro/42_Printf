/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/04/29 22:58:33 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define PLUS	1
# define MINUS	2
# define HASH	4
# define ZERO	8
# define SPACE	16

# define LLONG	0x4C
# define LL 	0x6C6C
# define LONG	0x6C
# define HH		0x6868
# define H		0x68
# define J		0x6A
# define T		0x74
# define Z		0x7A

# define SPECIFIERS		"diuoxXfFeEgGaAcspn%"
# define SPECIFIERS1	"uoxXcspn"
# define SPECIFIERS2	"diucspn"
# define SPECIFIERS3	"cdpn"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include "../lib/libft.h"

struct s_opt
{
	char	flags;
	int		width;
	int		precision;
	int		length;
	char	specifier;
	char	text[2048];
	int		count;
} g_opt;

/*
** ----------------------------------------------------------------------------
**               Funcoes para obtenção de dados e buffer
**               Functions for obtaining data and buffer
**-----------------------------------------------------------------------------
*/

int		ft_printf(const char *format, ...);
char	search_percent(char *text);
int		message_buffer(char c);
char	*add_buffer(char c, char *buffer, int size);
void	send_buffer(char *text);
void	clear_struct();

/*
**-----------------------------------------------------------------------------
**     Funcoes para tratamento de especificadores, flags, largura e precisao
**       Functions for treatment of specifiers, flags,  width and precision
**-----------------------------------------------------------------------------
*/

int			specifier_options(char *subtext);
char		*flag_options(char *parameters, char specifier);
char		solve_incompatible(char flags, char specifier);
char		solve_plus(char flags, char specifier);
char		solve_minus(char flags, char specifier);
char		solve_hash(char flags, char specifier);
char		solve_zero(char flags, char specifier);
char		solve_space(char flags, char specifier);
char		*width_options(char *parameters);
char		*precision_options(char *parameters);
char		*length_options(char *parameters);

/*
**-----------------------------------------------------------------------------
**            Funcoes para tratamento de argumentos
**            Functions for treatment of arguments
**-----------------------------------------------------------------------------
*/

void		message_arg_solve(va_list list);
void		store_int (long long int value);
void		store_float (long double value);
void		store_char (char c);
void		store_string(char *text);
char		*manager_precision(char *source, int total);
char	    *manager_width(char *source, int total);
char		*resize_result(char *result, char c, int size);

/*
**-----------------------------------------------------------------------------
**            Funcoes resposaveis por impressao na tela
**                 Functions for print on screen
**-----------------------------------------------------------------------------
*/
int			ft_printstr(char *text);

/*
**-----------------------------------------------------------------------------
**  Funcoes resposaveis por conversao de base e conversao de int para string
**         Functions to convert base and convert int for string
**-----------------------------------------------------------------------------
*/
char	*ft_itoa_base(long long int n);
char	*get_base(long long int value, int b);
char	*str_toupper(char *source);
long long int	convert_int(long long int value);
void	create_buffer();
void	store_u_int(long long int value);
unsigned long long int	convert_u_int(long long int value);
char	*ft_u_itoa_base(unsigned long long int n);
int		convert_char(long double value, int precision);
char	*get_u_base(unsigned long long int value, int b);
unsigned long long int	store_pointer(void *ptr);
int		round_number(char *value, int precision);
int		mount_float(long long int eint, char *dint, int precision);
int		store_sci(long double value);
int		count_expoent(long double value);
int		solve_expoent(int value);
#endif
