# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/15 15:00:21 by bfruchar          #+#    #+#              #
#    Updated: 2017/09/28 14:25:11 by bfruchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a
SRC= ft_memchr.c \
ft_str_tab_len.c \
ft_putnbr_fd.c \
ft_putnbr.c \
ft_striter.c \
ft_atoi.c \
ft_strnew.c \
ft_strequ.c \
ft_strnequ.c \
ft_memcmp.c \
ft_putstr.c \
ft_striteri.c \
ft_strnstr.c \
ft_bzero.c \
ft_memcpy.c \
ft_memccpy.c \
ft_putstr_fd.c \
ft_strjoin.c \
ft_strrchr.c \
ft_isalnum.c \
ft_memdel.c \
ft_strcat.c \
ft_strlcat.c \
ft_strsplit.c \
ft_isalpha.c \
ft_memmove.c \
ft_strchr.c \
ft_strlen.c \
ft_strstr.c \
ft_isascii.c \
ft_memset.c \
ft_strclr.c \
ft_strmap.c \
ft_strsub.c \
ft_isdigit.c \
ft_putchar.c \
ft_strcmp.c \
ft_strmapi.c \
ft_strtrim.c \
ft_isprint.c \
ft_putchar_fd.c \
ft_strcpy.c \
ft_strncat.c \
ft_tolower.c \
ft_itoa.c \
ft_putendl.c \
ft_strdel.c \
ft_strncmp.c \
ft_toupper.c \
ft_memalloc.c \
ft_putendl_fd.c \
ft_strdup.c \
ft_strncpy.c \
ft_lstnew.c \
ft_lstdel.c \
ft_lstdelone.c \
ft_lstadd.c \
ft_lstiter.c \
ft_lstmap.c \
ft_swap.c \
ft_reverse.c \
ft_is_space.c \
ft_is_number.c \
get_next_line.c \
ft_print_params.c
OBJ= $(SRC:.c=.o)

FLAGS=  -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@ gcc $(FLAGS) -c $(SRC)
	@ ar rc $(NAME) $(OBJ)

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f $(NAME)

re: fclean all
