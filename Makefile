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
			wid_pre_len.c \
			ft_printf.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isdigit.c \
			ft_itoa.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_substr.c \
			ft_toupper.c

OBJ = $(patsubst %.c, $(PATHOBJ)%.o, $(SRCS))
VPATH = %.c sources

all : libftprintf.a
	echo "--> Sucesso!!!"

libftprintf.a : $(OBJ)
	ar -rcs $@ $^

$(PATHOBJ)%.o: %.c
	clang -Wall -Wextra -c -o $@ $< -I headers/

clean:
	rm $(PATHOBJ)*.o
	rm libftprintf.a

