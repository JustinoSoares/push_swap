# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 11:42:26 by jsoares           #+#    #+#              #
#    Updated: 2024/08/08 13:08:40 by jsoares          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
ARQ = main.c operations.c \
	operations2.c error.c
OBJ = main.o operations.o \
	operations2.o error.o

all: $(NAME)	

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(ARQ) -o $(NAME)
clean: 
	@rm -rf $(OBJ)
fclean: clean
	@rm -rf $(NAME)
re: fclean all