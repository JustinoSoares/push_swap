/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_on_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:10:16 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/22 18:10:54 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_on_top_a(t_stack **stack_a, int index_a)
{
	int		cont;
	t_stack	*tmp;

	cont = 0;
	tmp = *stack_a;
	if (index_a <= (stack_size(tmp) / 2))
	{
		while (cont < index_a)
		{
			rotate(stack_a, 'a');
			cont++;
		}
	}
	else
	{
		index_a = stack_size(tmp) - index_a;
		while (cont < index_a)
		{
			rr_ab(stack_a, 'a');
			cont++;
		}
	}
}

void	put_on_top_b(t_stack **stack_b, int index_b)
{
	int		cont;
	t_stack	*tmp;

	cont = 0;
	tmp = *stack_b;
	if (index_b <= (stack_size(tmp) / 2))
	{
		while (cont < index_b)
		{
			rotate(stack_b, 'b');
			cont++;
		}
	}
	else
	{
		index_b = stack_size(tmp) - index_b;
		while (cont < index_b)
		{
			rr_ab(stack_b, 'b');
			cont++;
		}
	}
}

int	index_less(int a, int b)
{
	if (a == 0 || b == 0)
		return (0);
	if (a < b)
		return (a);
	return (b);
}

void	put_on_top(t_stack **stack_a, int index_a, t_stack **stack_b,
		int index_b)
{
	int	cont;
	int	less;

	if (index_a != 0 && index_b != 0 && (index_b <= (stack_size(*stack_b) / 2)
			&& index_a <= (stack_size(*stack_a) / 2)))
	{
		cont = 0;
		less = index_less(index_a, index_b);
		while (cont < less)
		{
			rr(stack_a, stack_b);
			cont++;
		}
		index_a = index_a - less;
		index_b = index_b - less;
	}
	put_on_top_a(stack_a, index_a);
	put_on_top_b(stack_b, index_b);
}
