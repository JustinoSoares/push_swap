# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: justinosoares <justinosoares@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 11:42:26 by jsoares           #+#    #+#              #
#    Updated: 2024/08/18 23:18:07 by justinosoar      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
ARQ = main.c operations.c \
	operations2.c error.c \
	sort.c checker.c utils.c
OBJ = main.o operations.o \
	operations2.o error.o \
	sort.o checker.o utils.o

all: $(NAME)	

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(ARQ) -o $(NAME)
clean: 
	@rm -rf $(OBJ)
fclean: clean
	@rm -rf $(NAME)
re: fclean all