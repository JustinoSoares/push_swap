/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinosoares <justinosoares@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:55:33 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/21 20:40:20 by justinosoar      ###   ########.fr       */
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
	free(*stack);
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
	write(1, "Error\n", 6);
	free_stack(*stack);
	exit(1);
}

void	ft_error2(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	allocate_error(t_stack **stack)
{
	fprintf(stderr, "Erro ao alocar memória\n");
	ft_free(stack);
	exit(1);
}
