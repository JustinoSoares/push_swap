/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:18:17 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/22 18:26:53 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*calc_cost_goo_b(int *tab, t_stack **stack_a, t_stack **stack_b,
		t_stack *tmp_a)
{
	t_aux_sort	aux;

	aux.cont = 0;
	aux.getter = 0;
	tab = malloc(sizeof(int) * (SIZE_TAB));
	if (!tab)
		ft_free_dup(stack_a, stack_b);
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
	if ((INDEX_A != 0 && INDEX_B != 0) && (tab[INDEX_A] <= (stack_size(*stack_a)
				/ 2) && tab[INDEX_B] <= (stack_size(*stack_b) / 2)))
		aux.cont = get_cost_rr(aux.opt_a, aux.opt_b, aux.getter);
	tab[COST] = cheaper(tab[COST], (aux.opt_a + aux.opt_b - aux.cont));
	return (tab);
}

void	sort_goo_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	int		**tab;

	ft_send_without_verify(stack_a, stack_b);
	while (stack_size(*stack_a) >= 3)
	{
		if (is_sort_3(stack_a))
			break ;
		tab = malloc(sizeof(int *) * (stack_size(*stack_a)));
		if (!tab)
			free_tab(tab, *stack_a);
		tmp_a = *stack_a;
		get_cost_a(tab, stack_a, stack_b, tmp_a);
		free_matriz(tab, stack_size(*stack_a));
		push(stack_a, stack_b, 'b');
	}
	put_on_top_b(stack_b, get_index((*stack_b), max_value(*stack_b)));
}

void	get_cost_b(int **tab, t_stack **stack_a, t_stack **stack_b,
		t_stack *tmp_b)
{
	t_aux_sort	aux;

	aux.row = 0;
	while (tmp_b)
	{
		tab[aux.row] = calc_cost_goo_a(tab[aux.row], stack_a, stack_b, tmp_b);
		tmp_b = tmp_b->next;
		aux.row++;
	}
	aux.index_cheaper = ft_index_cheaper(tab, stack_size(*stack_b));
	if (aux.index_cheaper < 0)
		return ;
	put_on_top(stack_a, tab[aux.index_cheaper][INDEX_A], stack_b,
		tab[aux.index_cheaper][INDEX_B]);
}
