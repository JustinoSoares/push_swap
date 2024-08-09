/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:43:05 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/09 15:44:47 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack **stack)
{
    t_stack *tmp;

    tmp = *stack;
    while (tmp->next)
    {
        if (tmp->num > tmp->next->num)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

void    sort_3(t_stack **stack)
{
    while (!is_sorted(stack) && (*stack)->next)
    {
        if ((*stack)->num > (*stack)->next->num)
            swap(stack, 'a');
        else
            rra(stack);
    }  
}

/*
    se a pilha tiver  mais de 3 elementos empura no maximo 2 elementos
*/
void    sort_any(t_stack *stack_a, t_stack *stack_b)
{
    int send_without_verify;

    if (stack_size(stack_a) > 3)
    {
        if (stack_size(stack_a) == 4)
            send_without_verify = 1;
        else
            send_without_verify = 2;
        while(send_without_verify-- > 0)
            push(&stack_a, &stack_b, 'a');
    }
}