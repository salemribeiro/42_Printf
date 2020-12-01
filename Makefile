# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salem <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/06 09:08:01 by salem             #+#    #+#              #
#    Updated: 2020/11/30 23:12:42 by salem            ###   ########.fr        #
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
			type_u_int.c \
			type_pointer.c \
			type_sci.c \
			uitoa_base.c \
			wid_pre_len.c \
			solve_signals.c \
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

BSRCS	=	buffer_functions_bonus.c \
			flag_options_bonus.c \
			itoa_base_bonus.c \
			message_arg_solve_bonus.c \
			print_funcions_bonus.c \
			specifier_options_bonus.c \
			type_and_flag_bonus.c \
			type_char_bonus.c \
			type_double_bonus.c \
			type_generic_bonus.c \
			type_int_bonus.c \
			type_u_int_bonus.c \
			type_pointer_bonus.c \
			type_sci_bonus.c \
			uitoa_base_bonus.c \
			wid_pre_len_bonus.c \
			solve_signals_bonus.c \
			ft_printf_bonus.c \
			ft_bzero_bonus.c \
			ft_calloc_bonus.c \
			ft_isdigit_bonus.c \
			ft_itoa_bonus.c \
			ft_strdup_bonus.c \
			ft_strjoin_bonus.c \
			ft_strlcpy_bonus.c \
			ft_strlen_bonus.c \
			ft_substr_bonus.c \
			ft_toupper_bonus.c \
			ft_atoi_bonus.c

OBJ = $(patsubst %.c, %.o, $(SRCS))
BOBJ = $(patsubst %.c, %.o, $(BSRCS))

VPATH = %.c sources

ifdef BONUS
	OBJ = $(BOBJ)
endif

all : $(NAME)

bonus:
	$(MAKE) BONUS=1 all

$(NAME) : $(OBJ)
	ar -rcs $@ $^

%.o: %.c
	$(CC) -g -Werror -Wall -Wextra -c -o $@ $< -I headers/

clean :
	rm *.o

fclean : clean
	rm libftprintf.a

re : fclean all
