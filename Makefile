# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 16:17:22 by ccodiga           #+#    #+#              #
#    Updated: 2018/12/11 12:04:46 by ccodiga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl
SRC = *.c
OBJ = $(SRC:.c=.o)
FLAGS = -g -Wall -Wextra -Werror
LIB = libft/libft.a

$(NAME): $(LIB)
	 @gcc $(FLAGS) -o $(NAME) $(SRC) $(LIB);
	 @echo compiling ft_ssl

all: $(NAME)

$(LIB):
	@make -C libft/

clean:
	@rm -rf $(OBJ) libft/$(OBJ)
	@echo deleting binary files

fclean: clean
	@rm -rf $(NAME) libft/libft.a
	@echo deleting libft.a and ft_ssl

re: fclean all

.PHONY : all, re, clean, fclean
