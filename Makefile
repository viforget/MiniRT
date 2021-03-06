# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viforget <viforget@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 07:57:46 by viforget          #+#    #+#              #
#    Updated: 2021/02/23 13:46:28 by viforget         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
FLAGS = -Wall -Wextra -Werror -I includes
MFLAGS = -lmlx -framework Opengl -framework Appkit
CC = @gcc -I includes
LIBDIR = libft
MLX = mlx

LIBBIN = libmlx.dylib

SRC = main.c\
	  arguments.c\
	  get_object.c\
	  light.c\
	  utils.c\
	  utils2.c\
	  utils3.c\
	  rotation.c\
	  camera.c\
	  error.c\
	  display.c\
	  vector.c\
	  calc_coord.c\
	  distance.c\
	  color.c\
	  square.c\
	  cylindre.c\
	  bmp.c\
	  cy_color.c\
	  mlx_function.c\
	  get_next_line.c


O_FILES = $(SRC:%.c=%.o)

FLAGLIB = -L$(LIBDIR)

all: $(NAME)

bonus: all

$(NAME): $(O_FILES)
			@make -C $(MLX)
			@cp $(MLX)/$(LIBBIN) .
			@make all -C $(LIBDIR)
			$(CC) $(FLAGS) $(MFLAGS) -o $(NAME) $(LIBBIN) $(O_FILES) $(LIBDIR)/libft.a
			@echo "\033[32mCOMPILATION OK\033[0m"

clean:
		@rm -rf $(O_FILES) $(LIBBIN)
			@make clean -C $(LIBDIR)
			@make clean -C $(MLX)
			@echo "\033[36mCLEAN OK\033[0m"

fclean: clean
		@rm -rf $(NAME)
			@make fclean -C $(LIBDIR)
			@make clean -C $(MLX)
			@echo "\033[36mFCLEAN OK\033[0m"

lib:
		@make re -C $(LIBDIR)

norm:
		@norminette $(SRC)

normlib:
		@norminette $(LIBDIR)/*.c

re: fclean all

.PHONY: all fclean clean re lib norm normlib
