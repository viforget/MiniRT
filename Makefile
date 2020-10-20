# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viforget <viforget@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 07:57:46 by viforget          #+#    #+#              #
#    Updated: 2020/09/29 09:53:40 by viforget         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MiniRT
FLAGS = -Wall -Wextra -Werror -I includes
CC = @gcc
LIBDIR = libft

SRC = main.c\

O_FILES = $(SRC:%.c=%.o)

FLAGLIB = -L$(LIBDIR)

all: $(NAME)

$(NAME): $(O_FILES) lib
			@make all -C $(LIBDIR)
			@gcc $(FLAGS) -o $(NAME) $(O_FILES)
			@echo "\033[32mCOMPILATION OK\033[0m"

clean:
		@rm -rf $(O_FILES)
			@make clean -C $(LIBDIR)
			@echo "\033[36mCLEAN OK\033[0m"

fclean: clean
		@rm -rf $(NAME)
			@make fclean -C $(LIBDIR)
			@echo "\033[36mFCLEAN OK\033[0m"

lib:
		@make re -C $(LIBDIR)

norm:
		@norminette $(SRC)

normlib:
		@norminette $(LIBDIR)/*.c

re: fclean all

.PHONY: all fclean clean re lib norm normlib
