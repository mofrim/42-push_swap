# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 11:37:05 by fmaurer           #+#    #+#              #
#    Updated: 2024/08/20 13:53:59 by fmaurer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC			= cc

CFLAGS	= -Wall -Wextra -Werror

LIBFT_PATH	= ./libft
LIBFT				= $(LIBFT_PATH)/libft.a

SRC_FILES =	./push_swap.c \
						./general_funcs.c \
						./utils.c \
						./more_utils.c \
						./stack_ops_push.c \
						./stack_ops_swap.c \
						./stack_ops_rot.c \
						./stack_ops_revrot.c \
						./stack_ops_print.c \
						./quick_sort.c \
						./smart_dsts.c \
						./smart_sort.c \
						./smart_utils.c \
						./smart_targets.c \
						./smart_move.c

SRC = $(patsubst ./%.c,%.c,$(SRC_FILES))

all: $(NAME)

$(NAME): $(SRC) | $(LIBFT)
	cc -o $(NAME) $^ $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_PATH) all

push: 
	cc -g -o $(NAME) $(SRC) $(LIBFT) && ./push_swp

test2:		$(NAME)
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test3:		$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5:		$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:	$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:	$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test1000:	$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

clean: fclean

fclean:
	@make -s -C $(LIBFT_PATH) fclean
	@echo "Removing $(NAME) binary..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re push
