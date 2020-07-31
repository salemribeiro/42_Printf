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

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include "libft.h"

#define PLUS	1
#define MINUS	2
#define HASH	4
#define ZERO	8
#define SPACE	16

#define LLONG	0x4C
#define LL 		0x6C6C
#define LONG	0x6C
#define HH		0x6868
#define H		0x68
#define J		0x6A
#define T		0x74
#define Z		0x7A

#define FORBIDEN	"diuoxXfFeEgGaAcspn%"
#define FORBIDEN1	"uoxXcspn"
#define FORBIDEN2	"diucspn"
#define FORBIDEN3	"cdpn"

struct s_options
{
	char	flags;
	int		width;
	int		precision;
	int		length;
	char	specifier;
	char	text[2048];
}typedef	t_options;

t_options parameters;

void			tabela_de_tipos();
/*
** ----------------------------------------------------------------------------
**               Funcoes para obtenção de dados e buffer
**               Functions for obtaining data and buffer
**-----------------------------------------------------------------------------
** --> ft_printf.c <--
*/

int		ft_printf(const char *format, ...);
char	search_percent(char *text);
int		message_buffer(char c);
char	*add_buffer(char c, char *buffer, int size);
void	send_buffer(char *text);
void	clear_struct();

/*
**-----------------------------------------------------------------------------
**     Funcoes para tratamento de especificadores flags, largura e precisao
**         Functions for treatment of specifiers, width and precision
**-----------------------------------------------------------------------------
** --> specifier_options.c <--
*/

int			specifier_options(char *subtext);

/*
** --> flag_options.c <--
*/

char		*flag_options(char *f, char specifier);
void		solve_incompatible(int *flags);

/*
** --> type_and_flag.c <--
*/

void		solve_plus(int *flags, char specifier);
void		solve_minus(int *flags, char specifier);
void		solve_hash(int *flags, char specifier);
void		solve_zero(int *flags, char specifier);
void		solve_space(int *flags, char specifier);

/*
** --> width_and_precision_options.c <--
*/

char		*width_options(char *f);
char		*precision_options(char *f, char specifier);
char		*length_options(char *f);

/*
**-----------------------------------------------------------------------------
**            Funcoes para tratamento de argumentos
**            Functions for treatment of arguments
**-----------------------------------------------------------------------------
** --> argument_options.c <--
*/

void		message_arg_solve(va_list list, char specifier);
void		store_int (long long int value);
void		store_float (long double value);
char		*put_zero(char *source, int total);
char		*resize_result(char *result, char c, int size);

/*
**-----------------------------------------------------------------------------
**            Funcoes resposaveis por impressao na tela
**                 Functions for print on screen
**-----------------------------------------------------------------------------
** --> print_functions.c <--
*/
int			ft_printstr(char *text);

/*
**-----------------------------------------------------------------------------
**  Funcoes resposaveis por conversao de base e conversao de int para string
**         Functions to convert base and convert int for string
**-----------------------------------------------------------------------------
** --> ft_itoa_base.c <--
*/
char	*ft_itoa_base(long long int n, char base);
char	*get_base(unsigned long long int value, int b);
char	*str_toupper(char *source);

#endif
