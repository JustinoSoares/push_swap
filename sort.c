/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinosoares <justinosoares@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:43:05 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/10 23:05:55 by justinosoar      ###   ########.fr       */
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
void    sort_any(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_a;
    t_stack *tmp_b;
    int **tab;
    int row;
    int opt_a;
    int opt_b;

    row = 0;
    tmp_a = *stack_a; 
    int send_without_verify;

    if (stack_size(tmp_a) > 3)
    {
        if (stack_size(tmp_a) == 4)
            send_without_verify = 1;
        else
            send_without_verify = 2;
        while(send_without_verify-- > 0)
            push(stack_a, stack_b, 'a');
    }
    tmp_a = *stack_a; 
    tmp_b = *stack_b;
    // em vez de if deve ir um while
    if (stack_size(tmp_a) > 3)
    {
        printf("maior que 3\n");
        while (tmp_b)
        {
            tab = malloc(sizeof(int) * (stack_size(tmp_b) + 1));
            if (!tab)
                allocate_error();
            tab[row] = malloc(sizeof(int) * (SIZE_TAB + 1));
                // valor
                tab[row][0] = tmp_b->num;
                //Valor de destino na stack_a
                tab[row][1] = next_min(tmp_a, tab[row][0]);
                //index na stack_a
                tab[row][2] = get_index(tmp_a, tab[row][1]);
                if (tab[row][2] < (stack_size(tmp_a) / 2))
                    opt_a = tab[row][2];
                else
                    opt_a = stack_size(tmp_a) - tab[row][2];
                //index na stack_b
                tab[row][3] = get_index(tmp_b, tab[row][0]);
                if (tab[row][3] < (stack_size(tmp_b) / 2))
                    opt_b = tab[row][3];
                else
                    opt_b = stack_size(tmp_b) - tab[row][3];
                tab[row][4] = opt_a + opt_b;
                tmp_b = tmp_b->next;
                printf("custo = %d\n", tab[row][4]);
                row++;
        }    
    }
}