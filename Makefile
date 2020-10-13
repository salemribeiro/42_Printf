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

PATHSRC	=	./sources/
PATHOBJ =	./objects/

SRCS	=	buffer_functions.c \
			flag_options.c \
			ft_printf.c \
			ft_printf.h \
			itoa_base.c \
			message_arg_solve.c \
			print_funcions.c \
			specifier_options.c \
			type_and_flag.c \
			type_char.c \
			type_double.c \
			type_generic.c \
			type_int.c \
			type_pointer.c \
			type_sci.c \
			uitoa_base.c \
			wid_pre_len.c

OBJ = $(patsubst %.c, %.o, $(SRCS))

VPATH = ./

all : libftprintf.a
	@echo "--> Sucesso!!!"

libftprintf.a : $(OBJ)
	@echo "-->  Linkando arquivos"
	@ar -rcs $@ $^

%.o: %.c
	@echo "--> Compilando arquivos objeto  FT_PRINTF"
	clang -Wall -Wextra -c -o $@ $< -I libft/ -I sources/

clean:
	@echo "--- Removendo arquivos gerados"
	rm objects/*.o
	rm libftprintf.a

