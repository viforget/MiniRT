# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viforget <viforget@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 15:34:08 by viforget          #+#    #+#              #
#    Updated: 2020/10/15 23:43:55 by viforget         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = @gcc

CFLAGS = -Wall -Wextra -Werror -c 

SRC = ft_atoi.c\
	  ft_bzero.c\
	  ft_calloc.c\
	  ft_freetab.c\
	  ft_itoa.c\
	  ft_isalpha.c\
	  ft_isalnum.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_maxmin.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memcpy.c\
	  ft_memccpy.c\
	  ft_memmove.c\
	  ft_memset.c\
	  ft_putchar_fd.c\
	  ft_putendl_fd.c\
	  ft_putnbr_fd.c\
	  ft_putstr_fd.c\
	  ft_settab.c\
	  ft_strchr.c\
	  ft_strdup.c\
	  ft_strjoin.c\
	  ft_strlcat.c\
	  ft_strlcpy.c\
	  ft_strlen.c\
	  ft_strncmp.c\
	  ft_strmapi.c\
	  ft_strnew.c\
	  ft_strnstr.c\
	  ft_strrchr.c\
	  ft_strtrim.c\
	  ft_split.c\
	  ft_substr.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  
SRC_BONUS = ft_lstadd_back_bonus.c\
			ft_lstadd_front_bonus.c\
			ft_lstclear_bonus.c\
			ft_lstdelone_bonus.c\
			ft_lstiter_bonus.c\
			ft_lstlast_bonus.c\
			ft_lstmap_bonus.c\
			ft_lstnew_bonus.c\
			ft_lstsize_bonus.c\

OBJ = $(SRC:%.c=%.o)

OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@echo "\033[32mCOMPILATION LIBFT\033[0m"

bonus : $(OBJ_BONUS) $(NAME)
		@ar rc $(NAME) $(OBJ_BONUS)
		@echo "\033[35mCOMPILATION BONUS\033[0m"

clean :
		@/bin/rm -f $(OBJ) $(OBJ_BONUS)
		@echo "\033[36mCLEAN OK\033[0m"

fclean :
		@/bin/rm -f $(OBJ) $(OBJ_BONUS) $(NAME)
		@echo "\033[36mFCLEAN OK\033[0m"

re : fclean all

.PHONY:  all clean fclean re
