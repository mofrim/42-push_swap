# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 11:37:05 by fmaurer           #+#    #+#              #
#    Updated: 2024/08/29 13:21:07 by fmaurer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC			= cc

CFLAGS	= -Wall -Wextra -Werror

LIBFT_PATH	= ./libft
LIBFT				= $(LIBFT_PATH)/libft.a

SRC_FILES =	./push_swap.c \
						./stack_funcs.c \
						./pushb_but_three.c \
						./utils.c \
						./get_max_min.c \
						./more_utils.c \
						./stack_ops_push.c \
						./stack_ops_swap.c \
						./stack_ops_rot.c \
						./stack_ops_revrot.c \
						./stack_ops_print.c \
						./quicksort.c\
						./smart_dsts.c \
						./smart_sort.c \
						./smart_utils.c \
						./smart_targets.c \
						./smart_move.c

SRC = $(patsubst ./%.c,%.c,$(SRC_FILES))

all: $(NAME)

$(NAME): $(SRC) | $(LIBFT)
	cc $(CFLAGS) -o $(NAME) $^ $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_PATH) all

push: 
	cc -g -o $(NAME) $(SRC) $(LIBFT) && ./push_swap

test2:		$(NAME)
					$(eval ARG = $(shell shuf -i 0-100 -n 2 | sed "s/\$$/-50/" | bc))
					./push_swap $(ARG) | testing/checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test3:		$(NAME)
					# $(eval ARG = $(shell shuf -i 0-100 -n 3))
					$(eval ARG = $(shell shuf -i 0-100 -n 3 | sed "s/\$$/-50/" | bc))
					./push_swap $(ARG) | testing/checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5:		$(NAME)
					# $(eval ARG = $(shell shuf -i 0-5000 -n 5))
					$(eval ARG = $(shell shuf -i 0-5000 -n 5 | sed "s/\$$/-2500/" | bc))
					./push_swap $(ARG) | testing/checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:	$(NAME)	
					# $(eval ARG = $(shell shuf -i 0-5000 -n 100))
					$(eval ARG = $(shell shuf -i 0-5000 -n 100 | sed "s/\$$/-2500/" | bc))
					./push_swap $(ARG) | testing/checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:	$(NAME)
					# $(eval ARG = $(shell shuf -i 0-5000 -n 500))
					$(eval ARG = $(shell shuf -i 0-5000 -n 500 | sed "s/\$$/-2500/" | bc))
					./push_swap $(ARG) | testing/checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test1000:	$(NAME)
					# $(eval ARG = $(shell shuf -i 0-5000 -n 1000))
					$(eval ARG = $(shell shuf -i 0-5000 -n 1000 | sed "s/\$$/-2500/" | bc))
					./push_swap $(ARG) | testing/checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100py: $(NAME)
					$(eval ARG = $(shell testing/tester.py))
					@./push_swap $(ARG) | testing/checker_linux $(ARG) > /dev/null
					@./push_swap $(ARG) | wc -l >> ops.log

clean: fclean

fclean:
	@make -s -C $(LIBFT_PATH) fclean
	@echo "Removing $(NAME) binary..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re push
