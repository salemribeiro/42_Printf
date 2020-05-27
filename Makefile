#
#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfreitas                                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/29 23:01:06 by sfreitas          #+#    #+#              #
#    Updated: 2020/04/29 23:01:42 by sfreitas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
SRCS = main.c ft_printf.c ./libft/ft_calloc.c ./libft/ft_bzero.c ./libft/ft_strlcpy.c
OBJS = *.o
CPARAMS = -c
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=70 -g
CC = clang
AR = ar
ARPARAMS = -rc



all: $(NAME)

$(NAME):
	$(CC) $(CPARAMS) $(CFLAGS) $(SRCS)
	$(AR) $(ARPARAMS) $(NAME) $(OBJS)

bonus:	$(NAME)

noflags:
	$(CC) $(CPARAMS) $(SRCS)
	$(AR) $(ARPARAMS) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

