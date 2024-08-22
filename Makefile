# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 11:42:26 by jsoares           #+#    #+#              #
#    Updated: 2024/08/22 14:05:18 by jsoares          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
BONUS = checker
ARQ_BONUS = check/bonus.c srcs/operations.c \
			srcs/utils.c check/utils.c check/libft.c srcs/error.c srcs/checker.c srcs/operations2.c  srcs/sort.c
ARQ = srcs/main.c srcs/operations.c \
	srcs/operations2.c srcs/error.c \
	srcs/sort.c srcs/checker.c srcs/utils.c
OBJ = $(ARQ:.c=.o)
OBJ_BONUS = $(ARQ_BONUS:.c=.o)

all: $(NAME)	

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJ_BONUS)
			$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(BONUS)
clean: 
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_BONUS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BONUS)

re: fclean all