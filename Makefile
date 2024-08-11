# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 11:37:05 by fmaurer           #+#    #+#              #
#    Updated: 2024/08/10 09:04:01 by fmaurer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swp

CC			= cc

CFLAGS	= -Wall -Wextra -Werror

LIBFT_PATH	= ./libft
LIBFT				= $(LIBFT_PATH)/libft.a

SRC =	push_swp.c \
			general_funcs.c \
			stack_operations1.c

all: $(NAME)

$(NAME): $(SRC) | $(LIBFT)
	cc -o $(NAME) $^ $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_PATH) all

push: 
	cc -o $(NAME) $(SRC) $(LIBFT) && ./push_swp

clean: fclean

fclean:
	@make -s -C $(LIBFT_PATH) fclean
	@echo "Removing $(NAME) binary..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re push
