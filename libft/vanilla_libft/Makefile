# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/13 12:18:50 by cjulienn          #+#    #+#              #
#    Updated: 2021/08/12 11:57:57 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./ft_atoi.c \
	  ./ft_bzero.c \
	  ./ft_calloc.c \
	  ./ft_free_and_return.c \
	  ./ft_intlen_base.c \
	  ./ft_isalnum.c \
	  ./ft_isalpha.c \
	  ./ft_isascii.c \
	  ./ft_isdigit.c \
	  ./ft_isprint.c \
	  ./ft_itoa.c \
	  ./ft_lltoa.c \
	  ./ft_memccpy.c \
	  ./ft_memchr.c \
	  ./ft_memcmp.c \
	  ./ft_memcpy.c \
	  ./ft_memmove.c \
	  ./ft_memset.c \
	  ./ft_protec_strdup.c \
	  ./ft_putchar_fd.c \
	  ./ft_putendl_fd.c \
	  ./ft_putlnbr_base.c \
	  ./ft_putlnbr_fd.c \
	  ./ft_putnbr_fd.c \
	  ./ft_putstr_fd.c \
	  ./ft_split.c \
	  ./ft_strchr.c \
	  ./ft_strdel.c \
	  ./ft_strdup.c \
	  ./ft_strjoin_and_free.c \
	  ./ft_strjoin.c \
	  ./ft_strlcat.c \
	  ./ft_strlcpy.c \
	  ./ft_strlen.c \
	  ./ft_strmapi.c \
	  ./ft_strncmp.c \
	  ./ft_strnstr.c \
	  ./ft_strtrim.c \
	  ./ft_strrchr.c \
	  ./ft_substr.c \
	  ./ft_tolower.c \
	  ./ft_toupper.c
	  
BONUS =	$(SRCS) \
		./ft_lstadd_back.c \
		./ft_lstadd_front.c \
		./ft_lstnew.c \
		./ft_lstsize.c \
		./ft_lstlast.c \
		./ft_lstdelone.c \
		./ft_lstclear.c \
		./ft_lstiter.c \
		./ft_lstmap.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

RM = rm -f

NAME = vanillalibft.a
	
.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
	ar -rcs $(NAME) $(OBJS)

all:	
	$(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re:		fclean $(NAME)

bonus:	$(BONUS_OBJS)
	ar -rcs $(NAME) $(BONUS_OBJS)

lib:	$(NAME) clean

lib_bonus:	bonus clean

.PHONY: all clean fclean re bonus lib lib_bonus
