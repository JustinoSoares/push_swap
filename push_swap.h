/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 06:43:57 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/09 11:26:15 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
    int num;
    struct s_stack *next;
}   t_stack;

void    sa(t_stack **stack);
void    sb(t_stack **stack);
void    ra(t_stack **stack);
void    error(t_stack *stack);
void    ra(t_stack **stack);
void    rra(t_stack **stack);
void    allocate_error(void);
void    ft_write(t_stack *stack);
void    append_end(t_stack **stack, int num);
void    append_start(t_stack **stack, int num);
void    pop_start(t_stack **stack);
int stack_size(t_stack *stack);
void    push(t_stack **stack_from, t_stack **stack_to, char ab);
int max_value(t_stack *stack);
int min_value(t_stack *stack);
int next_max(t_stack *stack, int num);
int next_min(t_stack *stack, int num);

#endif