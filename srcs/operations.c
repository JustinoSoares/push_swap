/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:18:09 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/22 18:07:26 by jsoares          ###   ########.fr       */
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
	t_stack	*old_head;

	if (!(*stack) || !(*stack)->next)
		return ;
	old_head = *stack;
	new = malloc(sizeof(t_stack));
	if (!new)
		ft_error(&new);
	new->num = (*stack)->num;
	new->next = NULL;
	*stack = (*stack)->next;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	free(old_head);
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
	t_stack	*last;
	int		last_num;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	last_num = last->num;
	tmp->next = NULL;
	free(last);
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
