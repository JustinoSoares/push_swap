/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:55:33 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/22 17:45:31 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack **stack)
{
	t_stack	*node;

	while ((*stack)->next)
	{
		node = *stack;
		free(node);
		*stack = (*stack)->next;
	}
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		free(temp);
		stack = stack->next;
	}
}

void	ft_error(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	write(1, "Error\n", 6);
	ft_free_stack(stack);
	exit(1);
}

void	ft_error2(void)
{
	write(1, "Error\n", 6);
	exit(1);
}
