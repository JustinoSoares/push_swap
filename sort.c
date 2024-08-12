/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:43:05 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/12 12:43:41 by jsoares          ###   ########.fr       */
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
            rr(stack, 'a');
    }  
}




/*
    se a pilha tiver  mais de 3 elementos empura no maximo 2 elementos
*/
int ft_send_without_verify(t_stack *stack)
{
    if (stack_size(stack) > 3)
    {
        if (stack_size(stack) == 4)
            return(1);
        else if (stack_size(stack) > 4)
            return (2);
    }
    return (0);
}

void    sort_any(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_a;
    t_stack *tmp_b;
    t_stack *tmp_b2;
    t_aux_sort aux;
    int **tab;
    tmp_a = *stack_a; 

    aux.send_without_verify = ft_send_without_verify(tmp_a);
    while(aux.send_without_verify-- > 0)
            push(stack_a, stack_b, 'a');
    tmp_a = *stack_a; 
    tmp_b = *stack_b;
    while (stack_size(tmp_a) >= 3)
    {
        tmp_a = *stack_a;
        if (stack_size(tmp_a) == 3)
        {
            sort_3(stack_a);
            break ;
        }
        tmp_b = *stack_b;
        tab = malloc(sizeof(int *) * (stack_size(tmp_b) + 1));
        if (!tab)
            allocate_error();
        aux.row = 0;
        while (tmp_b)
        {
            tab[aux.row] = malloc(sizeof(int) * (SIZE_TAB + 1));
            if (!tab[aux.row])
            {
                allocate_error();
            }
                tab[aux.row][VALUE_B] = tmp_b->num;
                tmp_b = tmp_b->next;
                tab[aux.row][VALUE_DEST] = next_min(tmp_a, tab[aux.row][VALUE_B]);
                tab[aux.row][INDEX_A] = get_index(tmp_a, tab[aux.row][VALUE_DEST]);
                if (tab[aux.row][INDEX_A] <= (stack_size(tmp_a) / 2))
                    aux.opt_a = tab[aux.row][INDEX_A];
                else
                    aux.opt_a = stack_size(tmp_a) - tab[aux.row][2];
                tmp_b2 = *stack_b;
                tab[aux.row][INDEX_B] = get_index(tmp_b2, tab[aux.row][VALUE_B]);
                if (tab[aux.row][INDEX_B] <= (stack_size(tmp_b2) / 2))
                    aux.opt_b = tab[aux.row][INDEX_B];
                else
                    aux.opt_b = stack_size(tmp_b2) - tab[aux.row][3];
                tab[aux.row][COST] = aux.opt_a + aux.opt_b;
                aux.row++;
        }
        aux.index_cheaper = ft_index_cheaper(tab);
        put_on_top(stack_a, tab[aux.index_cheaper][2], stack_b, tab[aux.index_cheaper][3]);
        push(stack_a, stack_b, 'a');
    }
}
