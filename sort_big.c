/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:14:10 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/16 16:16:18 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int piv(t_stack **stack)
{
    int half;
    int min;
    t_stack *tmp_x;
    t_stack *tmp_y;

    tmp_y = *stack;
    half = stack_size(*stack) / 2;
    while (tmp_y)
    {
        min = 0;
        tmp_x = *stack;
        while (tmp_x)
        {
            if (tmp_y->num > tmp_x->num)
                min++;
            tmp_x = tmp_x->next;
        }
        if (min == half)
            return (tmp_y->num);
        tmp_y = tmp_y->next;
    }
    return (0);
}

int last_num(t_stack **stack)
{
    t_stack *tmp;

    tmp = *stack;
    while (tmp->next)
        tmp = tmp->next;
    return  (tmp->num);
}

void    sort_big(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_a;

    tmp_a = *stack_a;
    while (tmp_a)
    {
        if (stack_size(*stack_a) == 3)
        {
            sort_3(stack_a);
            break;
        }
        if (tmp_a->num < piv(stack_a))
            push(stack_a, stack_b, 'b');
        else if (tmp_a->next->num < piv(stack_a))
        {
            swap(stack_a, 'a');
            push(stack_a, stack_b, 'b');
        }
        else
            rotate(stack_a, 'a');
        tmp_a = tmp_a->next;
    }
}

void    selection(t_stack **stack_a, t_stack **stack_b)
{
    while (stack_size(*stack_b) > 0)
    {
        put_on_top_b(stack_b, max_value(*stack_a));
        push(stack_b, stack_a, 'a');
    }
}
