# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/09 16:49:18 by cjulienn          #+#    #+#              #
#    Updated: 2021/08/09 17:54:28 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./get_next_line.c 

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

RM = rm -f

NAME = libftgnl.a

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

re:		fclean $(NAME)

lib:	$(NAME) clean

.PHONY: all clean fclean re lib
