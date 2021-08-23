# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/10 13:39:17 by cjulienn          #+#    #+#              #
#    Updated: 2021/08/23 17:21:33 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = ./pipex.c \
	   ./utils.c \
	   ./utils_2.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

RM = rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo pipex program successfully made !!!

all: 
	$(NAME)

clean:
	$(RM) *.o

fclean:	clean
	$(RM) $(NAME)

tmp: all clean

.PHONY: all clean fclean tmp
