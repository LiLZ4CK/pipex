# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 14:54:41 by zwalad            #+#    #+#              #
#    Updated: 2022/02/22 14:55:54 by zwalad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex

CC := cc 

CFLAGS := -Wall -Wextra -Werror

RM = @rm -f

SRC := main.c \
		pip_utils.c \
		pip_utils2.c \
		pip_utils3.c \

OBJ := $(SRC:%.c=	%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all