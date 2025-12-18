# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yannis <yannis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/18 02:51:49 by yannis            #+#    #+#              #
#    Updated: 2025/12/18 12:34:12 by yannis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
CC = cc
CFLAGS = -Wall -Werror -Wextra -I
AR = ar rcs

SRCS = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
# NAME is the name of the final library file
# NEADER is the name of the .h file so it makes it easier to change it later
# CC is the compiler to use
# CFLAGS are all the flags for Warning Errors and Extra warnings
# the -I explicitly tell the compiler to look in the current directory for headers(does it by default)
# AR is the archive command to make static library
# static library is a collection of compliled .o files, bundled together into a single file (libft.a in our case) .a means archive created with ar and contain multiples .o files
# ar is archive tool, r replace or add files to archive, c create archive if they are not existing and s create an idex for the archive
# SRCS list all source .c files and \ allow continuation to next line
# OBJS list all object .o files
# $(SRCS:.c=.o) is pattern substitution that turn all .c files in .o files
# all means default target so it run when we type make without arguments
# and it will depends on NAME to build the library libft.a
# $(NAME) is the rule to create the library and depends on all .o files
# so this command create libft.a from all .o files
# %.o: %.c is the pattern rule for compiling .c files in .o files
# the echo command make output clearer (optional)
# %: wildcar that matches any filename.
# the rule is simple, just creat any .o files using its corresponding .c files
# naturally if libft.h changes have to recomplie everything
# $< and $@ are automatic variable
# the first mean the prerequisite (.c file) while the latter means the target name (.o file)
# then the command complie .c file in  .o file
# clean remove all .o files, and -f flag is force removal so we have no error and the file is inexistant
# fclean is 'full clean' so it remove .o files and the libft.a
# it depends on clean so it always clean first then removes libft.a at the end
# re means rebuild everything from scratch, we run fclean first the rebuild all
# .PHONY declares targets that don't creat files
# without this if a file was named "clean" or "all" make would think the target is up to date
# so phony tell make those are commands not files