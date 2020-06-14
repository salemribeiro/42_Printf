#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salem <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/13 10:56:32 by salem             #+#    #+#              #
#    Updated: 2020/06/13 19:51:52 by salem            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#                                                Nome do projeto | Project name
PROJ_NAME=ft_printf.a

SOURCES=$(wildcard souces/*.c)

say_hello:
	echo $< $(SOURCES) 

