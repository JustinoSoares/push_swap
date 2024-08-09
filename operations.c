/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:18:09 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/08 17:56:11 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_stack **stack)
{
    int swap;

    if ((*stack)->next)
    {
        swap = (*stack)->num;
        (*stack)->num = (*stack)->next->num;
        (*stack)->next->num = swap;
        write(1, "sa\n", 3); 
    }
}

void    sb(t_stack **stack)
{
    int swap;

    if ((*stack)->next)
    {
        swap = (*stack)->num;
        (*stack)->num = (*stack)->next->num;
        (*stack)->next->num = swap;
        write(1, "sb\n", 3); 
    }
}

void    ra(t_stack **stack)
{
    t_stack *tmp; 
    t_stack *new;
    
    new = malloc(sizeof(t_stack));
    if (!new)
        allocate_error();
    new->num = (*stack)->num;
    new->next  = NULL;
    *stack = (*stack)->next;
    tmp = *stack;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    write(1, "ra\n", 3);
}

void    rra(t_stack **stack)
{
    t_stack *tmp;
    int     last_num;

    tmp = *stack;
    while (tmp->next)
            tmp = tmp->next;
    last_num = tmp->num;
    tmp = *stack; 
    while (tmp->next && tmp->next->next)
            tmp = tmp->next;
    tmp->next = NULL;
    append_start(stack, last_num);
    write(1, "rra\n", 4);
}

void    push(t_stack **stack_from, t_stack **stack_to, char ab)
{
    int top;
    
    top = (*stack_from)->num;
    pop_start(stack_from);
    append_start(stack_to, top);
    write(1, "p", 1);
    write(1, &ab, 1);
    write(1, "\n", 1);
}
