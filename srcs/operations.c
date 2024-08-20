/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:18:09 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/20 11:14:09 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char ab)
{
	int	swap;

	if ((*stack)->next)
	{
		swap = (*stack)->num;
		(*stack)->num = (*stack)->next->num;
		(*stack)->next->num = swap;
		if (ab != '\0')
		{
			write(1, "s", 1);
			write(1, &ab, 1);
			write(1, "\n", 1);
		}
	}
}

void	rotate(t_stack **stack, char ab)
{
	t_stack	*tmp;
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		allocate_error(&new);
	new->num = (*stack)->num;
	new->next = NULL;
	*stack = (*stack)->next;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	if (ab != '\0')
	{
		write(1, "r", 1);
		write(1, &ab, 1);
		write(1, "\n", 1);
	}
}

void	rr_ab(t_stack **stack, char ab)
{
	t_stack	*tmp;
	int		last_num;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	last_num = tmp->num;
	tmp = *stack;
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	append_start(stack, last_num);
	if (ab != '\0')
	{
		write(1, "rr", 2);
		write(1, &ab, 1);
		write(1, "\n", 1);
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rr_ab(stack_a, 'r');
	rr_ab(stack_b, '\0');
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, 'r');
	rotate(stack_b, '\0');
}

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
