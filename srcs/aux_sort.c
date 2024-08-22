/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:24:58 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/22 18:26:41 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_dup(t_stack **stack_a, t_stack **stack_b)
{
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	exit(1);
}

int	cheaper(int first, int second)
{
	if (first < second)
		return (first);
	else
		return (second);
}

void	free_tab(int **tab, t_stack *stack)
{
	free_matriz(tab, stack_size(stack));
	exit(1);
}

void	free_matriz(int **tab, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
}
