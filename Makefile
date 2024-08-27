# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 11:42:26 by jsoares           #+#    #+#              #
#    Updated: 2024/08/27 14:39:55 by jsoares          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
BONUS = checker
ARQ_BONUS = check/bonus.c  check/operations_bonus.c srcs/operations.c \
			srcs/utils.c check/utils.c check/libft.c srcs/error.c srcs/checker.c \
			srcs/operations2.c  srcs/sort.c \
			srcs/aux_sort.c srcs/calc_cost_a.c srcs/calc_cost_b.c \
			srcs/ft_index_cheaper.c srcs/operations3.c srcs/put_on_top.c \
			check/get_next_line.c check/get_next_line_utils.c srcs/utils2.c 
ARQ = srcs/main.c srcs/operations.c \
	srcs/operations2.c srcs/error.c \
	srcs/sort.c srcs/checker.c srcs/utils.c \
	srcs/aux_sort.c srcs/calc_cost_a.c srcs/calc_cost_b.c \
	srcs/ft_index_cheaper.c srcs/operations3.c srcs/put_on_top.c \
	srcs/utils2.c 

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