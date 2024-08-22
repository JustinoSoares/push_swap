/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:07:06 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/22 18:13:45 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_from, t_stack **stack_to, char ab)
{
	int	top;

	top = (*stack_from)->num;
	pop_start(stack_from);
	append_start(stack_to, top);
	if (ab != '\0')
	{
		write(1, "p", 1);
		write(1, &ab, 1);
		write(1, "\n", 1);
	}
}

int	max_value(t_stack *stack)
{
	int	max;

	max = stack->num;
	while (stack)
	{
		if (stack->num > max)
			max = stack->num;
		stack = stack->next;
	}
	return (max);
}

int	min_value(t_stack *stack)
{
	int	min;

	min = stack->num;
	while (stack)
	{
		if (stack->num < min)
			min = stack->num;
		stack = stack->next;
	}
	return (min);
}

int	next_max(t_stack *stack, int num)
{
	t_stack	*tab;
	int		result;

	tab = NULL;
	if (max_value(stack) > num)
	{
		while (stack)
		{
			if (stack->num > num)
				append_end(&tab, stack->num);
			stack = stack->next;
		}
		result = min_value(tab);
	}
	else
		result = min_value(stack);
	ft_free_stack(&tab);
	return (result);
}

int	next_min(t_stack *stack, int num)
{
	t_stack	*tab;
	int		result;

	tab = NULL;
	if (min_value(stack) < num)
	{
		while (stack)
		{
			if (stack->num < num)
				append_end(&tab, stack->num);
			stack = stack->next;
		}
		result = max_value(tab);
	}
	else
		result = max_value(stack);
	ft_free_stack(&tab);
	return (result);
}
