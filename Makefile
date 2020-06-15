#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salem <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/13 10:56:32 by salem             #+#    #+#              #
#    Updated: 2020/06/14 19:38:04 by sfreitas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#                                                Nome do projeto | Project name

NAME=libftprintf.a

LIB_DIR = ./lib
SOURCES_DIR=./sources


SOURCES=$(wildcard $(SOURCES_DIR)/*.c)

OBJSOURCES=$(patsubst $(SOURCES_DIR)/%.c, ./%.o, $(SOURCES))

CC=clang

FLAGS=	-c		\
		-g


$(NAME):$(OBJSOURCES)
#	$(MAKE) -C ./lib
	ar -r $(NAME) $(OBJSOURCES)


%.o: $(SOURCES_DIR)/%.c
	$(CC) $(FLAGS) $< -I ./sources -I ./lib -o $@

clean:
	rm $(OBJSOURCES)

fclean: clean
	rm $(NAME)
teste: main.c libftprintf.a ./lib/libft.a
	clang -c main.c -I ./sources -I ./lib
	clang main.o -L ./ -L ./lib -lftprintf -lft
	./a.out
