/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:28:39 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/20 11:42:08 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# define BUFFER_SIZE 1024

# include "../srcs/push_swap.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

t_stack	*execute(int ac, char **av);
int		ft_strcmp(char *s1, char *s2);
void	rrr_bonus(t_stack **stack_a, t_stack **stack_b);
void	rr_bonus(t_stack **stack_a, t_stack **stack_b);
void	push_bonus(t_stack **stack_from, t_stack **stack_to);
t_stack	*execute(int ac, char **av);
#endif