/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 06:43:57 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/11 16:23:22 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE_TAB 5
typedef struct s_stack
{
    int num;
    struct s_stack *next;
}   t_stack;

void    swap(t_stack **stack, char ab);
void    rotate(t_stack **stack, char ab);
void    error(t_stack *stack);
void    rr(t_stack **stack, char ab);
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
int is_sorted(t_stack **stack);
void    sort_3(t_stack **stack);
void    sort_any(t_stack **stack_a, t_stack **stack_b);
int get_index(t_stack *stack, int num);
int ft_index_cheaper(int **tab);
void    put_on_top_a(t_stack *stack_a, int index_a);
void    put_on_top_b(t_stack *stack_b, int index_b);
void    put_on_top(t_stack *stack_a, int index_a, t_stack *stack_b, int index_b);
void    rr_ab(t_stack **stack_a, t_stack **stack_b);

#endif