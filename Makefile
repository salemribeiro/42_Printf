# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salem <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/06 09:08:01 by salem             #+#    #+#              #
#    Updated: 2020/10/24 16:35:47 by sfreitas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
FLAGS	= -Wall -Werror -Wextra -c -o
NAME	= libftprintf.a

PATHOBJ = ./objects/


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
			ft_toupper.c \
			ft_atoi.c

OBJ = $(patsubst %.c, $(PATHOBJ)%.o, $(SRCS))
VPATH = %.c sources

all : start libftprintf.a
	@echo "                                     SUCCESS !!!"

start :
	@echo "------------------------------------------------"
	@echo "|           START MAKE FT_PRINTF 42SP          |"
	@echo "|                                              |"
	@echo "|   by: Salem Freitas (sfreitas)               |"
	@echo "| mail: sfreitas@student.42sp.org.br           |"
	@echo "------------------------------------------------"
	@echo "                            creating objects... "

libftprintf.a : $(OBJ)
	@echo "+ Criando link libft_printf.h"
	@ar -rcs $@ $^

$(PATHOBJ)%.o: %.c
	@echo "+ Create $@"
	@$(CC) -g -Werror -Wall -Wextra -c -o $@ $< -I headers/

clean :
	@echo "                      removing objects files..."
	@rm $(PATHOBJ)*.o
	@echo "                                       DONE !!!"

fclean : clean
	@echo "                                removing lib..."
	@rm libftprintf.a
	@echo "                                       DONE !!!"

re : fclean all

test : all
	$(CC) -g -I ./headers tests/testemain.c -lftprintf -L .
	@clear
	@./a.out
