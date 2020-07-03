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
}typedef	t_options;

void			tabela_de_tipos();
/*
** ----------------------------------------------------------------------------
**               Funcoes para obtenção de dados e buffer
**               Functions for obtaining data and buffer
**-----------------------------------------------------------------------------
** --> ft_printf.c <--
*/

int			ft_printf(const char *format, ...);
char		search_percent(char *text);
char		*message_buffer(char c);
char		*add_buffer(char c, char *buffer, int size);
t_options	big_hub(int value, char field);
void		send_buffer(char *text);

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

void		message_arg_solve(void *value, char specifier);
void		store_int (void *value);
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
#endif
