/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinosoares <justinosoares@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:43:05 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/12 21:55:52 by justinosoar      ###   ########.fr       */
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

static int *calc_cost_goo_b(int   *tab, t_stack **stack_a, t_stack **stack_b, t_stack *tmp_b)
{
    t_aux_sort aux;
    t_stack *tmp_a;
    t_stack *tmp_b2;

    tmp_a = *stack_a;
    tab = malloc(sizeof(int) * (SIZE_TAB + 1));
    if (!tab)
    {
        allocate_error();
    }
    tab[VALUE_B] = tmp_b->num;
    tab[VALUE_DEST] = next_min(tmp_a, tab[VALUE_B]);
    tab[INDEX_A] = get_index(tmp_a, tab[VALUE_DEST]);
    if (tab[INDEX_A] <= (stack_size(tmp_a) / 2))
        aux.opt_a = tab[INDEX_A];
    else
        aux.opt_a = stack_size(tmp_a) - tab[INDEX_A];
    tmp_b2 = *stack_b;
    tab[INDEX_B] = get_index(tmp_b2, tab[VALUE_B]);
    if (tab[INDEX_B] <= (stack_size(tmp_b2) / 2))
        aux.opt_b = tab[INDEX_B];
    else
        aux.opt_b = stack_size(tmp_b2) - tab[3];
    tab[COST] = aux.opt_a + aux.opt_b;
    return (tab);
}

void    sort_goo_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_a;
    t_stack *tmp_b;
    t_aux_sort aux;
    int **tab;

    tmp_a = *stack_a; 
    aux.send_without_verify = ft_send_without_verify(tmp_a);
    while(aux.send_without_verify-- > 0)
        push(stack_a, stack_b, 'a');
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
            tab[aux.row] = calc_cost_goo_b(tab[aux.row], stack_a, stack_b, tmp_b);
            tmp_b = tmp_b->next;
            aux.row++;
        }
        aux.index_cheaper = ft_index_cheaper(tab);
        put_on_top(stack_a, tab[aux.index_cheaper][INDEX_A], stack_b, tab[aux.index_cheaper][INDEX_B]);
        push(stack_a, stack_b, 'a');
    }
}


static int *calc_cost_goo_a(int   *tab, t_stack **stack_a, t_stack **stack_b, t_stack *tmp_b)
{
    t_aux_sort aux;
    t_stack *tmp_a;
    t_stack *tmp_b2;

    tmp_a = *stack_a;
    tab = malloc(sizeof(int) * (SIZE_TAB + 1));
    if (!tab)
    {
        allocate_error();
    }
    tab[VALUE_B] = tmp_b->num;
    tab[VALUE_DEST] = next_max(tmp_a, tab[VALUE_B]);
    tab[INDEX_A] = get_index(tmp_a, tab[VALUE_DEST]);
    if (tab[INDEX_A] <= (stack_size(tmp_a) / 2))
        aux.opt_a = tab[INDEX_A];
    else
        aux.opt_a = stack_size(tmp_a) - tab[INDEX_A];
    tmp_b2 = *stack_b;
    tab[INDEX_B] = get_index(tmp_b2, tab[VALUE_B]);
    if (tab[INDEX_B] <= (stack_size(tmp_b2) / 2))
        aux.opt_b = tab[INDEX_B];
    else
        aux.opt_b = stack_size(tmp_b2) - tab[3];
    tab[COST] = aux.opt_a + aux.opt_b;
    return (tab);
}
void    sort_goo_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_b;
    t_aux_sort aux;
    int **tab;

    tmp_b = *stack_b; 
    while (stack_size(tmp_b) > 0)
    {
        tmp_b = *stack_b;
        tab = malloc(sizeof(int *) * (stack_size(tmp_b) + 1));
        if (!tab)
            allocate_error();
        aux.row = 0;
        while (tmp_b)
        {
            tab[aux.row] = calc_cost_goo_a(tab[aux.row], stack_a, stack_b, tmp_b);
            tmp_b = tmp_b->next;
            aux.row++;
        }
        aux.index_cheaper = ft_index_cheaper(tab);
        put_on_top(stack_a, tab[aux.index_cheaper][INDEX_A], stack_b, tab[aux.index_cheaper][INDEX_B]);
        push(stack_b, stack_a, 'b');
        tmp_b = *stack_b;
        put_on_top_a(stack_a, get_index((*stack_a), min_value(*stack_a)));
    }
}

void    sort_any(t_stack **stack_a, t_stack **stack_b)
{
        sort_goo_b(stack_a, stack_b);
        sort_goo_a(stack_a, stack_b);
        if (is_sorted(stack_a))
            printf("OK\n");
        else
            printf("KO\n");
}