# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/09 18:00:27 by cjulienn          #+#    #+#              #
#    Updated: 2021/08/09 18:45:21 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

NAME_GNL = libftgnl.a
GNL_PATH =  ./gnl_libft/

NAME_FT_PRINTF = libftprintf.a
FT_PRINTF_PATH = ./ft_printf_libft/

NAME_VANILLA = vanillalibft.a
VANILLA_PATH = ./vanilla_libft/

INCLUDES_PATH = ./includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME):	
	$(MAKE) -C $(GNL_PATH)
	$(MAKE) -C $(FT_PRINTF_PATH)
	$(MAKE) -C $(VANILLA_PATH) bonus
	ar -rc $(NAME) $(VANILLA_PATH)$(NAME_VANILLA) $(GNL_PATH)$(NAME_GNL) $(FT_PRINTF_PATH)$(NAME_FT_PRINTF)
	ranlib $(NAME)
	@echo libft.a successfully made !!!

all: 
	$(NAME)

clean:
	$(MAKE) -C $(GNL_PATH) clean
	$(MAKE) -C $(FT_PRINTF_PATH) clean
	$(MAKE) -C $(VANILLA_PATH) clean

fclean:	clean
	$(MAKE) -C $(GNL_PATH) fclean
	$(MAKE) -C $(FT_PRINTF_PATH) fclean
	$(MAKE) -C $(VANILLA_PATH) fclean
	$(RM) $(NAME)
	
re:		fclean $(NAME)

lib:	$(NAME) clean

.PHONY: all clean fclean re lib