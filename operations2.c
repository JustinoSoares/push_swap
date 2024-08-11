/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:32:17 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/11 18:11:33 by jsoares          ###   ########.fr       */
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

int get_index(t_stack *stack, int num)
{
    int index;
    index = 0;
    while (stack)
    {
        if (stack->num == num)
            return(index);
        stack = stack->next;
        index++;
    }
    return (index);
}
// retorna o indice do custo mais barato;
int ft_index_cheaper(int **tab)
{
    int cont;
    int cost;
    int index;
    
    cont = 0;
    index  = 0;
    cost = tab[0][4];
    /// seria while
    while (tab[cont])
    {
        if (cost > tab[0][4])
        {
            cost = tab[0][4];
            index++;
        }
        cont++;
    }
    return (index);
}

void    put_on_top_a(t_stack *stack_a, int index_a)
{
    int cont;

    cont  = 0;
    if (index_a <= (stack_size(stack_a) / 2))
    {
        while (cont < index_a)
        {
            rotate(&stack_a, 'a');
            cont++;
        }
    }
    else
    {
        while (cont < index_a)
        {
            rr(&stack_a, 'a');
            cont++;
        }
    }
}

void    put_on_top_b(t_stack *stack_b, int index_b)
{
    int cont;

    cont  = 0;
    if (index_b <= (stack_size(stack_b) / 2))
    {
        while (cont < index_b)
        {
            rotate(&stack_b, 'b');
            cont++;
        }
    }
    else
    {
        while (cont < index_b)
        {
            rr(&stack_b, 'b');
            cont++;
        }
    }
}

void    put_on_top(t_stack *stack_a, int index_a, t_stack *stack_b, int index_b)
{
    int cont;

    cont = 0;
    if (index_a != index_b)
    {
        put_on_top_a(stack_a, index_a);
        put_on_top_b(stack_b, index_b);
    }
    else
    {
        while (cont < index_a)
        {
            rr_ab(&stack_a, &stack_b);
            cont++;   
        }
    }
}

