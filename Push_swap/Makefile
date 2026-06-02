# ***********/***************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/20 23:18:34 by sgarba            #+#    #+#              #
#    Updated: 2026/04/24 17:36:38 by sgarba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = push_swap.h
CC = cc
CFLAGS = -Wall -Werror -Wextra -I. -I Libft/
LIBFT = Libft/libft.a

SRCS = push_swap_main.c \
		push_swap_error_handler.c \
		push_swap_stack_handler.c \
		push_swap_push.c \
		push_swap_swap.c \
		push_swap_rotate.c \
		push_swap_reverse_rotate.c \
		push_swap_algo_helper.c \
		push_swap_algo_helper1.c \
		push_swap_algo.c \
		push_swap_manual_sort.c \
		push_swap_chunk.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC)  $(OBJS) -L Libft -lft -o $(NAME) 
	@echo "Built: $(NAME)"

$(LIBFT):
	@make -C Libft

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

clean:
	@make -C Libft clean
	@rm -f $(OBJS)
	@echo "Cleaned push_swap objects"

fclean: clean
	@make -C Libft fclean
	@rm -f $(NAME)
	@echo "Removed $(NAME)"

re: fclean all

.PHONY: all clean fclean re