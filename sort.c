/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:43:05 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/16 16:17:24 by jsoares          ###   ########.fr       */
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
            rr_ab(stack, 'a');
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

static int *calc_cost_goo_b(int   *tab, t_stack **stack_a, t_stack **stack_b, t_stack *tmp_a)
{
    t_aux_sort aux;
    t_stack *tmp_b;
    t_stack *tmp_b2;

    aux.cont = 0;
    tmp_b = *stack_b;
    tab = malloc(sizeof(int) * (SIZE_TAB + 1));
    if (!tab)
    {
        allocate_error();
    }
    tab[TARGET] = tmp_a->num;
    tab[DEST] = next_min(tmp_b, tab[TARGET]);
    tab[INDEX_A] = get_index((*stack_a), tab[TARGET]);
    if (tab[INDEX_A] <= (stack_size(*stack_a) / 2))
        aux.opt_a = tab[INDEX_A];
    else
        aux.opt_a = stack_size(*stack_a) - tab[INDEX_A];
    tmp_b2 = *stack_b;
    tab[INDEX_B] = get_index(tmp_b2, tab[DEST]);
    if (tab[INDEX_B] <= (stack_size(tmp_b2) / 2))
        aux.opt_b = tab[INDEX_B];
    else
        aux.opt_b = stack_size(tmp_b2) - tab[INDEX_B];
    //(tab[INDEX_A] <= (stack_size(*stack_a) / 2) && tab[INDEX_B] <= (stack_size(*stack_b) / 2)
    tab[COST] = aux.opt_a + aux.opt_b;
    if ((INDEX_A != 0 && INDEX_B != 0)  && (tab[INDEX_A] <= (stack_size(*stack_a) / 2) && tab[INDEX_B] <= (stack_size(*stack_b) / 2)))
    {
        if (aux.opt_a < aux.opt_b)
            aux.getter = aux.opt_a;
        else
            aux.getter = aux.opt_b;
        while (aux.cont < aux.getter)
            aux.cont++;
    }
    // (tab[INDEX_A] > (stack_size(*stack_a) / 2) && tab[INDEX_B] > (stack_size(*stack_b) / 2))
    else if ((INDEX_A != 0 && INDEX_B != 0) && (tab[INDEX_A] > (stack_size(*stack_a) / 2) && tab[INDEX_B] > (stack_size(*stack_b) / 2)))
    {
        aux.cont = 0;
        if (aux.opt_a < aux.opt_b)
            aux.getter = aux.opt_a;
        else
            aux.getter = aux.opt_b;
        while (aux.cont < aux.getter)
            aux.cont++;
    }
    tab[IS_DUPLE] = 0;
    if (tab[COST] > (aux.opt_a + aux.opt_b - aux.cont))
    {
        tab[COST] = (aux.opt_a + aux.opt_b) - aux.cont;
        tab[IS_DUPLE] = 1;
    }
    return (tab);
}

void    sort_goo_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_a;
    //t_stack *tmp_b;
    t_aux_sort aux;
    int **tab;

    tmp_a = *stack_a;
    aux.send_without_verify = ft_send_without_verify(tmp_a);
    while(aux.send_without_verify-- > 0)
        push(stack_a, stack_b, 'b');
    while (stack_size(*stack_a) >= 3)
    {
        if (stack_size(*stack_a) == 3)
        {
            sort_3(stack_a);
            break ;
        }
        tab = malloc(sizeof(int *) * (stack_size(*stack_a) + 1));
        if (!tab)
            allocate_error();
        aux.row = 0;
        tmp_a = *stack_a;
        while (tmp_a)
        {
            tab[aux.row] = calc_cost_goo_b(tab[aux.row], stack_a, stack_b, tmp_a);
            tmp_a = tmp_a->next;
            aux.row++;
        }
        aux.index_cheaper = ft_index_cheaper(tab);
        put_on_top(stack_a, tab[aux.index_cheaper][INDEX_A], stack_b, tab[aux.index_cheaper][INDEX_B], tab[aux.index_cheaper][IS_DUPLE]);
        push(stack_a, stack_b, 'b');
    }
    put_on_top_b(stack_b, get_index((*stack_b), max_value(*stack_b)));
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
    tab[TARGET] = tmp_b->num;
    tab[DEST] = next_max(tmp_a, tab[TARGET]);
    tab[INDEX_A] = get_index(tmp_a, tab[DEST]);
    if (tab[INDEX_A] <= (stack_size(tmp_a) / 2))
        aux.opt_a = tab[INDEX_A];
    else
        aux.opt_a = stack_size(tmp_a) - tab[INDEX_A];
    tmp_b2 = *stack_b;
    tab[INDEX_B] = get_index(tmp_b2, tab[TARGET]);
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

    while (stack_size(*stack_b) > 0)
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
        put_on_top(stack_a, tab[aux.index_cheaper][INDEX_A], stack_b, tab[aux.index_cheaper][INDEX_B], tab[aux.index_cheaper][IS_DUPLE]);
        push(stack_b, stack_a, 'a');
        tmp_b = *stack_b;
    }
    put_on_top_a(stack_a, get_index((*stack_a), min_value(*stack_a)));
}

void    sort_any(t_stack **stack_a, t_stack **stack_b)
{
        sort_big(stack_a, stack_b);
        selection(stack_a, stack_a);
        //sort_goo_b(stack_a, stack_b);
        //sort_goo_a(stack_a, stack_b);
}