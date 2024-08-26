/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:46:36 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/26 18:28:29 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus.h"

void	response(int is_sort, t_stack **stack)
{
	if (is_sort && *stack == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		*getter;
	static int	row;
	static int	col;

	stack_a = NULL;
	stack_b = NULL;
	if (!check_error(av, row, col))
		ft_error(&stack_a);
	stack_a = execute(ac, av);
	if (!is_dup(stack_a))
		ft_error(&stack_a);
	if (stack_a && !is_sorted(&stack_a) && ac >= 2)
	{
		while (1)
		{
			getter = get_next_line(0);
			if (!getter)
				break ;
			operations_bonus(&stack_a, &stack_b, getter);
			free(getter);
		}
		response(is_sorted(&stack_a), &stack_b);
	}
}
