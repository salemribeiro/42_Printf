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
# include <stdio.h> //remover a linha ao concluir o projeto
# include "libft/libft.h"

struct hub_op
{
	char	flags;
	int		width;
	int		precision;
	int		length;
	char	specifier;
};

void	tabela_de_tipos();
/*
** ----------------------------------------------------------------------------
**               Funcoes para obtenção de dados e buffer
**               Functions for obtaining data and buffer
**-----------------------------------------------------------------------------
** --> ft_printf.c <--
*/

int				ft_printf(const char *format, ...);
char			search_percent(char *text);
char			*mensage_buffer(char c);
char			*add_buffer(char c, char *buffer, int size);
struct hub_op	big_hub(int value, char field);

/*
**-----------------------------------------------------------------------------
**     Funcoes para tratamento de especificadores flags, largura e precisao
**         Functions for treatment of specifiers, width and precision
**-----------------------------------------------------------------------------
** --> specifier_options.c <--
*/

int		specifier_options(char *subtext);

/*
** --> flag_options.c <--
*/

char	*flag_options(char *f, char specifier);
void	fix_incompatible_flags(int *flags);

/*
** --> type_and_flag.c <--
*/

void	solve_plus_flag_with_types(int *flags, char specifier);
void	solve_minusflag_with_types(int *flags, char specifier);
void	solve_hash_flag_with_types(int *flags, char specifier);
void	solve_zero_flag_with_types(int *flags, char specifier);
void	solve_spaceflag_with_types(int *flags, char specifier);

/*
** --> width_and_precision_options.c <--
*/

char	*width_options(char *f);
char	*precision_options(char *f, char specifier);
char	*length_options(char *f);


/*
**-----------------------------------------------------------------------------
**            Funcoes para tratamento de argumentos
**            Functions for treatment of arguments
**-----------------------------------------------------------------------------
** --> argument_options.c <--
*/

void	mensage_arg_solve(void *value, char specifier);
void	store_int (void *value);

#endif
