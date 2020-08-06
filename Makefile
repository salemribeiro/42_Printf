# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salem <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/06 09:08:01 by salem             #+#    #+#              #
#    Updated: 2020/08/06 09:08:04 by salem            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRCS	= 	buffer_functions.c \
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

OBJS	=	$(SRCS:.c=.o)
#FLAG	=	-Wall -Werror -Wextra
#FLAG	=	-Wall -Werror -Wextra -g -fsanitize=address
FLAG	=	 -g
RM		=	rm -f
HEAD	= 	ft_printf.h
AR		=	ar -rcs
LDIR	=	lib/
LBFT	=	-lft
LPTF 	=	-lftprintf
LNAME	= 	lib/libft.a

all:		$(NAME)

$(NAME):
			$(MAKE) -C $(LDIR)
			gcc -c $(FLAG) $(SRCS) -I.$(HEAD)
			cp $(LNAME) $(NAME)
			$(AR) $(NAME) $(OBJS)

#$(NAME):
#			$(MAKE) -C $(LDIR)
#			gcc -c $(FLAG) $(SRCS) -I.$(HEAD) -L$(LDIR) $(LBFT)
#			cp $(LNAME) $(NAME)
#			$(AR) $(NAME) $(OBJS)

teste:		all clean
			gcc $(FLAG) main.c -L. $(LPTF) && ./a.out

clean:
			$(MAKE) clean -C $(LDIR)
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) fclean -C $(LDIR)
			$(RM) $(NAME)

re:			fclean all
			
.PHONY:		all clean fclean re bonus
