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

SRCS = push_swap_error_handle.c \
		push_swap.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C Libft
	@$(CC)  $(OBJS) -L Libft -lft -o $(NAME) 
	@echo "Built: $(NAME)"

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