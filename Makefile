# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/24 16:57:44 by bfruchar          #+#    #+#              #
#    Updated: 2017/09/28 09:53:36 by bfruchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = src/main.c \
	src/ft_parsing.c \
	src/ft_key_funct.c \
	src/ft_draw.c \
	src/ft_print_map.c

OBJ = main.o \
	  ft_parsing.o \
	  ft_key_funct.o \
	  ft_draw.o \
	  ft_print_map.o

CC = gcc

FLAGS = -Wall -Werror -Wextra

$(NAME) :
	@(make -C libft/ clean && make -C libft/)
	@(make -C minilibx/ clean && make -C minilibx/)
	@($(CC) $(FLAGS) -c $(SRC))
	@($(CC) $(FLAGS) $(OBJ) libft/libft.a -framework OpenGL -framework AppKit minilibx/libmlx.a -o $(NAME))
	@(echo "\x1b[32mFdf has been created.\x1b[0m")

all: $(NAME)

clean :
	@(rm -f $(OBJ))
	@(make -C libft/ clean)
	@(make -C minilibx/ clean)
	@(echo "\x1b[33mThe .o files have been deleted.\x1b[0m")

fclean : clean
	@(rm -f $(NAME))
	@(make -C libft/ fclean)
	@(echo "\x1b[31mEverything is clean.\x1b[0m")

re: fclean all
