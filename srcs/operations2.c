/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:32:17 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/22 18:13:37 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop_start(t_stack **stack)
{
	t_stack	*top;

	top = *stack;
	if (*stack)
		*stack = (*stack)->next;
	free(top);
}

void	append_start(t_stack **stack, int num)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		ft_error(&new);
	new->num = num;
	new->next = *stack;
	*stack = new;
}

void	append_end(t_stack **stack, int num)
{
	t_stack	*new;
	t_stack	*tmp;

	new = malloc(sizeof(t_stack));
	if (!new)
		ft_error(&new);
	new->num = num;
	new->next = NULL;
	if (*stack == NULL)
		*stack = new;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int	stack_size(t_stack *stack)
{
	int	length;

	length = 0;
	if (stack != NULL)
	{
		while (stack)
		{
			stack = stack->next;
			length++;
		}
	}
	return (length);
}

int	get_index(t_stack *stack, int num)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->num == num)
			return (index);
		stack = stack->next;
		index++;
	}
	return (index);
}
