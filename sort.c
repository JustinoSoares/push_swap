/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinosoares <justinosoares@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:43:05 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/18 01:27:30 by justinosoar      ###   ########.fr       */
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

static void    ft_send_without_verify(t_stack **stack_a, t_stack **stack_b)
{
    t_aux_sort aux;

    aux.send_without_verify = 0;
    if (stack_size(*stack_a) > 3)
    {
        if (stack_size(*stack_a) == 4)
            aux.send_without_verify = 1;
        else if (stack_size(*stack_a) > 4)
            aux.send_without_verify = 2;
    }
    while(aux.send_without_verify-- > 0)
        push(stack_a, stack_b, 'b');
}

static int get_cost_rr(int opt_a, int opt_b, int getter)
{
    int cont;
    
    cont = 0;
    if (opt_a < opt_b)
            getter = opt_a;
        else
            getter = opt_b;
        while (cont < getter)
            cont++;
    return (cont);
}
static int *calc_cost_goo_b(int   *tab, t_stack **stack_a, t_stack **stack_b, t_stack *tmp_a)
{
    t_aux_sort aux;

    aux.cont = 0;
    aux.getter = 0;
    tab = malloc(sizeof(int) * (SIZE_TAB + 1));
    if (!tab)
        allocate_error();
    tab[TARGET] = tmp_a->num;
    tab[DEST] = next_min(*stack_b, tab[TARGET]);
    tab[INDEX_A] = get_index((*stack_a), tab[TARGET]);
    if (tab[INDEX_A] <= (stack_size(*stack_a) / 2))
        aux.opt_a = tab[INDEX_A];
    else
        aux.opt_a = stack_size(*stack_a) - tab[INDEX_A];
    tab[INDEX_B] = get_index(*stack_b, tab[DEST]);
    if (tab[INDEX_B] <= (stack_size(*stack_b) / 2))
        aux.opt_b = tab[INDEX_B];
    else
        aux.opt_b = stack_size(*stack_b) - tab[INDEX_B];
    tab[COST] = aux.opt_a + aux.opt_b;
    if ((INDEX_A != 0 && INDEX_B != 0)  && (tab[INDEX_A] <= (stack_size(*stack_a) / 2) && tab[INDEX_B] <= (stack_size(*stack_b) / 2)))
        aux.cont = get_cost_rr(aux.opt_a, aux.opt_b, aux.getter);
    if (tab[COST] > (aux.opt_a + aux.opt_b - aux.cont))
        tab[COST] = (aux.opt_a + aux.opt_b) - aux.cont;
    return (tab);
}

int is_sort_3(t_stack *stack)
{
    if (stack_size(stack) == 3)
    {
        sort_3(&stack);
        return (1);
    }
    else
        return(0);
}
void    sort_goo_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_a;
    t_aux_sort aux;
    int **tab;

    ft_send_without_verify(stack_a, stack_b);
    while (stack_size(*stack_a) >= 3)
    {
        if (is_sort_3(*stack_a))
            break ;
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
        put_on_top(stack_a, tab[aux.index_cheaper][INDEX_A], stack_b, tab[aux.index_cheaper][INDEX_B]);
        push(stack_a, stack_b, 'b');
    }
    put_on_top_b(stack_b, get_index((*stack_b), max_value(*stack_b)));
}


static int *calc_cost_goo_a(int *tab, t_stack **stack_a, t_stack **stack_b, t_stack *tmp_b)
{
    t_aux_sort aux;


    tab = malloc(sizeof(int) * (SIZE_TAB + 1));
    if (!tab)
    {
        allocate_error();
    }
    tab[TARGET] = tmp_b->num;
    tab[DEST] = next_max(*stack_a, tab[TARGET]);
    tab[INDEX_A] = get_index(*stack_a, tab[DEST]);
    if (tab[INDEX_A] <= (stack_size(*stack_a) / 2))
        aux.opt_a = tab[INDEX_A];
    else
        aux.opt_a = stack_size(*stack_a) - tab[INDEX_A];
    tab[INDEX_B] = get_index(*stack_b, tab[TARGET]);
    if (tab[INDEX_B] <= (stack_size(*stack_b) / 2))
        aux.opt_b = tab[INDEX_B];
    else
        aux.opt_b = stack_size(*stack_b) - tab[INDEX_B];
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
        tab = malloc(sizeof(int *) * (stack_size(*stack_b) + 1));
        if (!tab)
            allocate_error();
        aux.row = 0;
        tmp_b = *stack_b;
        while (tmp_b)
        {
            tab[aux.row] = calc_cost_goo_a(tab[aux.row], stack_a, stack_b, tmp_b);
            tmp_b = tmp_b->next;
            aux.row++;
        }
        aux.index_cheaper = ft_index_cheaper(tab);
        put_on_top(stack_a, tab[aux.index_cheaper][INDEX_A], stack_b, tab[aux.index_cheaper][INDEX_B]);
        push(stack_b, stack_a, 'a');
    }
    put_on_top_a(stack_a, get_index((*stack_a), min_value(*stack_a)));
}

void    sort_any(t_stack **stack_a, t_stack **stack_b)
{
        sort_goo_b(stack_a, stack_b);
        sort_goo_a(stack_a, stack_b);
}