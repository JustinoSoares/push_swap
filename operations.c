/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:18:09 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/08 14:32:56 by jsoares          ###   ########.fr       */
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
    new = *stack;
    new->next  = NULL;
    *stack = (*stack)->next;
    tmp = *stack;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    write(1, "ra\n", 3);
}