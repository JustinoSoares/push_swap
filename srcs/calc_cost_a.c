/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:14:52 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/22 18:24:03 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*calc_cost_goo_a(int *tab, t_stack **stack_a, t_stack **stack_b,
		t_stack *tmp_b)
{
	t_aux_sort	aux;

	tab = malloc(sizeof(int) * (SIZE_TAB));
	if (!tab)
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return (NULL);
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

void	sort_goo_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*tmp_b;
	int			**tab;

	while (stack_size(*stack_b) > 0)
	{
		tab = malloc(sizeof(int *) * (stack_size(*stack_b)));
		if (!tab)
			free_tab(tab, *stack_b);
		tmp_b = *stack_b;
		get_cost_b(tab, stack_a, stack_b, tmp_b);
		free_matriz(tab, stack_size(*stack_b));
		push(stack_b, stack_a, 'a');
	}
	put_on_top_a(stack_a, get_index((*stack_a), min_value(*stack_a)));
}

void	get_cost_a(int **tab, t_stack **stack_a, t_stack **stack_b,
		t_stack *tmp_a)
{
	t_aux_sort	aux;

	aux.row = 0;
	while (tmp_a && stack_b)
	{
		tab[aux.row] = calc_cost_goo_b(tab[aux.row], stack_a, stack_b, tmp_a);
		tmp_a = tmp_a->next;
		aux.row++;
	}
	aux.index_cheaper = ft_index_cheaper(tab, stack_size(*stack_a));
	put_on_top(stack_a, tab[aux.index_cheaper][INDEX_A], stack_b,
		tab[aux.index_cheaper][INDEX_B]);
}

int	get_cost_rr(int opt_a, int opt_b, int getter)
{
	int	cont;

	cont = 0;
	if (opt_a < opt_b)
		getter = opt_a;
	else
		getter = opt_b;
	while (cont < getter)
		cont++;
	return (cont);
}
