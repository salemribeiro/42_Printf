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

void	tabela_de_tipos();
/*----------------------------------------------------------------------------*/
/*               Funcoes para obtenção de dados e buffer                      */
/*               Functions for obtaining data and buffer                      */
/*----------------------------------------------------------------------------*/
/*                                                    -->         ft_printf.c */
int		ft_printf(const char *format, ...);
char	*mensage_buffer(char c);
char	*add_buffer(char c, char *buffer, int size);
/*----------------------------------------------------------------------------*/
/*               Funcoes para tratamento de especificadores                   */
/*                  Functions for treatment of specifiers                     */
/*----------------------------------------------------------------------------*/
/*                                                    --> specifier_options.c */
int		specifier_options(char *subtext, void *arg);
/*----------------------------------------------------------------------------*/
/*                  Funcoes para tratamento de flags                          */
/*                      Flag handling functions                               */
/*----------------------------------------------------------------------------*/
/*                                                    -->      flag_options.c */
char	*flag_options(char *f, char specifier);
void	fix_incompatible_flags(char *flags);
/*                                                    -->     type_and_flag.c */
void	solve_plus_flag_with_types(char *flags, char specifier);
void	solve_minusflag_with_types(char *flags, char specifier);
void	solve_hash_flag_with_types(char *flags, char specifier);
void	solve_zero_flag_with_types(char *flags, char specifier);
void	solve_spaceflag_with_types(char *flags, char specifier);
/*----------------------------------------------------------------------------*/
/*                 Funcoes para tratamento de largura e precisao              */
/*                     Width treatment functions                              */
/*----------------------------------------------------------------------------*/
/*                                          --> width_and_precision_options.c */
char	*width_options(char *f);
char	*precision_options(char *f, char specifier);

#endif
