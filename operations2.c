/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:32:17 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/08 14:28:20 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void    ft_write(t_stack *stack)
{
        if (stack != NULL)
        {
           write(1, "elements\n", 9);
           while (stack)
           {
                printf("%d\n", stack->num);
                stack = stack->next;
           } 
        }
        else
            write(1, "Empty\n", 6);
}

void    pop_end(t_stack **stack, int num)
{
    t_stack *new;
    t_stack *tmp;
    
    new = malloc(sizeof(t_stack));
    if (!new)
        allocate_error();
    new->num = num;
    new->next = NULL;
    
    if (*stack == NULL)
        *stack = new;
    else
    {
        tmp = *stack;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}

int stack_size(t_stack *stack)
{
    int length;

    length = 0;
    if (stack != NULL)
    {
        while (stack)
        {
            stack = stack->next;
            length++;
        }
    }
    
    return (length);
}