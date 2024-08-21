/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:55:33 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/20 15:22:59 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack **stack)
{
	t_stack	*node;

	while ((*stack)->next)
	{
		node = *stack;
		*stack = (*stack)->next;
		free(node);
	}
	free(*stack);
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

void	ft_error(t_stack **stack)
{
	write(1, "Error\n", 6);
	ft_free(stack);
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
