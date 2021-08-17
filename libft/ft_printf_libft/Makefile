# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/09 16:54:22 by cjulienn          #+#    #+#              #
#    Updated: 2021/08/09 17:50:22 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  ./ft_printf.c \
		./conversions_1.c \
		./conversions_2.c 

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

RM = rm -f

NAME = libftprintf.a

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
	ar -rcs $(NAME) $(OBJS)

all:	
	$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

lib:	$(NAME) clean

re:		fclean $(NAME)

.PHONY: all clean fclean lib re
