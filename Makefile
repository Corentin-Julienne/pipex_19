# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 17:55:02 by cjulienn          #+#    #+#              #
#    Updated: 2021/08/23 18:39:40 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = ./srcs/pipex.c \
	   ./srcs/errors.c \
	   ./srcs/free.c

OBJS = $(SRCS:.c=.o)

INCLUDE_PATH = ./includes/
LIBFT_LIB = libft.a

LIBFT_PATH = ./libft/

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_PATH)

RM = rm -rf

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo pipex successfully made !!!

all: 
	$(NAME)

clean:
	$(MAKE) -C $(LIBFT_PATH)
	$(RM) $(OBJS)
	
fclean:	clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re