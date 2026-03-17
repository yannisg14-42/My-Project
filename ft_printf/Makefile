NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I. -I libft/
AR      = ar rcs
HEADER  = ft_printf.h

SRCS    = ft_printf.c ft_printf_utils.c ft_printf_utilss.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@cp libft/libft.a $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@echo "Built: $(NAME)"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

clean:
	@make -C libft clean
	@rm -f $(OBJS)
	@echo "Cleaned ft_printf objects"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "Removed $(NAME)"

re: fclean all

.PHONY: all clean fclean re
