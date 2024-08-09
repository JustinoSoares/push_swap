/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:32:17 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/09 11:40:08 by jsoares          ###   ########.fr       */
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

void    pop_start(t_stack **stack)
{
        *stack = (*stack)->next;
}

void    append_start(t_stack **stack, int num)
{
    t_stack *new;

    new = malloc(sizeof(t_stack));
    if (!new)
        allocate_error();
    new->num = num;
    new->next = *stack;
    *stack = new;
}

void    append_end(t_stack **stack, int num)
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

int max_value(t_stack *stack)
{
    int max;

    max = stack->num;
    while (stack)
    {
        if (stack->num > max)
            max = stack->num;
        stack = stack->next;
    }
    return (max);
}

int min_value(t_stack *stack)
{
    int min;

    min = stack->num;
    while (stack)
    {
        if (stack->num < min)
            min = stack->num;
        stack = stack->next;
    }
    return (min);
}

int next_max(t_stack *stack, int num)
{
    t_stack *tab;
    int result;
    
    if (max_value(stack) > num)
    {
         tab = malloc(sizeof(t_stack));
         if (!tab)
            allocate_error();
        tab = NULL;
        while (stack)
        {
            if  (stack->num > num)
                append_end(&tab, stack->num);
            stack = stack->next;
        }
        result = min_value(tab);
    }
    else 
        result = next_min(stack, num);
    return (result);
}

int next_min(t_stack *stack, int num)
{
    t_stack *tab;
    int result;

    if (min_value(stack) < num)
    {
        tab = malloc(sizeof(t_stack));
        if (!tab)
            allocate_error();
        tab = NULL;
        while (stack)
        {
            if  (stack->num < num)
                append_end(&tab, stack->num);
            stack = stack->next;
        }
        result = max_value(tab);
    }
    else
        result = next_max(stack, num);
    return (result);
}