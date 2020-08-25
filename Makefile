# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salem <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/06 09:08:01 by salem             #+#    #+#              #
#    Updated: 2020/08/25 20:51:07 by caio             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	buffer_functions.c \
			flag_options.c \
			ft_itoa_base.c \
			ft_printf.c \
			ft_u_itoa_base.c \
			message_arg_solve.c \
			print_funcions.c \
			specifier_options.c \
			type_and_flag.c \
			type_char.c \
			type_double.c \
			type_int.c \
			type_pointer.c \
			width_and_precision_options.c

OBJ = $(patsubst %.c, %.o, $(SRCS))

VPATH = sources/

all : libftprintf.a

libftprintf.a : $(OBJ)
	ar -rcs $@ $^

%.o: %.c
	clang -Wall -Wextra -c -o $@ $< -I lib/ -I sources/
