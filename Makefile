# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viforget <viforget@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 07:57:46 by viforget          #+#    #+#              #
#    Updated: 2020/11/05 15:23:06 by viforget         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MiniRT
FLAGS = -Wall -Wextra -Werror -I includes
MFLAGS = -lmlx -framework Opengl -framework Appkit
CC = @gcc -I includes
LIBDIR = libft

SRC = main.c\
	  arguments.c\
	  get_object.c\
	  light.c\
	  utils.c\
	  utils2.c\
	  camera.c\
	  error.c\
	  display.c\
	  vector.c\
	  Get_next_line/get_next_line.c

O_FILES = $(SRC:%.c=%.o)

FLAGLIB = -L$(LIBDIR)

all: $(NAME)

$(NAME): $(O_FILES)
			@make all -C $(LIBDIR)
			$(CC) $(FLAGS) $(MFLAGS) -o $(NAME) $(O_FILES)
			@echo "\033[32mCOMPILATION OK\033[0m"
dev : $(O_FILES)
			@make all -C $(LIBDIR)
			$(CC) -I includes $(MFLAGS) -o $(NAME) $(O_FILES) $(LIBDIR)/libft.a
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
