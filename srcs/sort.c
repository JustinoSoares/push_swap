/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:43:05 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/22 18:34:31 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_3(t_stack **stack)
{
	while (!is_sorted(stack) && (*stack)->next)
	{
		if ((*stack)->num > (*stack)->next->num)
			swap(stack, 'a');
		else
			rr_ab(stack, 'a');
	}
}

void	ft_send_without_verify(t_stack **stack_a, t_stack **stack_b)
{
	t_aux_sort	aux;

	aux.send_without_verify = 0;
	if (stack_size(*stack_a) > 3)
	{
		if (stack_size(*stack_a) == 4)
			aux.send_without_verify = 1;
		else if (stack_size(*stack_a) > 4)
			aux.send_without_verify = 2;
	}
	while (aux.send_without_verify-- > 0)
		push(stack_a, stack_b, 'b');
}

int	is_sort_3(t_stack **stack)
{
	if (stack_size(*stack) == 3)
	{
		sort_3(stack);
		return (1);
	}
	else
		return (0);
}

void	sort_any(t_stack **stack_a, t_stack **stack_b)
{
	sort_goo_b(stack_a, stack_b);
	sort_goo_a(stack_a, stack_b);
}
