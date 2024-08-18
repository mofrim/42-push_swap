# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 11:37:05 by fmaurer           #+#    #+#              #
#    Updated: 2024/08/16 19:42:06 by fmaurer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swp

CC			= cc

CFLAGS	= -Wall -Wextra -Werror

LIBFT_PATH	= ./libft
LIBFT				= $(LIBFT_PATH)/libft.a

SRC_FILES =	./push_swp.c \
						./general_funcs.c \
						./stack_ops1.c \
						./stack_ops_print1.c \
						./simple_sort.c \
						./quick_sort.c \
						./swap_sort.c \
						./pushb_sort.c \
						./stratsort.c \
						./strat_sim.c \
						./strat_do.c \
						./strat_utils.c \
						./dist_sort.c \
						./dist_sort_utils.c \
						./prep_stacks.c

SRC = $(patsubst ./%.c,%.c,$(SRC_FILES))

all: $(NAME)

$(NAME): $(SRC) | $(LIBFT)
	cc -o $(NAME) $^ $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_PATH) all

push: 
	cc -g -o $(NAME) $(SRC) $(LIBFT) && ./push_swp

clean: fclean

fclean:
	@make -s -C $(LIBFT_PATH) fclean
	@echo "Removing $(NAME) binary..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re push
