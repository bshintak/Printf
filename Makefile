# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 12:45:18 by bshintak          #+#    #+#              #
#    Updated: 2021/11/20 12:33:38 by bshintak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -g

NAME = libftprintf.a

SRC = 	ft_printf.c				\
		ft_base.c				\
		ft_main.c				\
		libft/ft_putchar.c		\
		libft/ft_putstr.c		\
		libft/ft_putnumber.c	\
		libft/ft_strlen.c		\
		libft/ft_strdup.c		\

OBJS = $(SRC:.c=.o)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	/bin/rm -rf $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all%
