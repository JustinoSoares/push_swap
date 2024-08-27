/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:46:36 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/27 10:40:45 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/bonus.h"

void	response(int is_sort, t_stack **stack)
{
	if (is_sort && *stack == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	check(int ac, char **av, int row, int col)
{
	char	**av2;

	av2 = ft_split(av[1]);
	if (ac == 2)
	{
		if (!check_error(av2, row, col))
		{
			ft_free_char(av2);
			return (0);
		}
	}
	else
	{
		row = 1;
		if (!check_error(av, row, col))
		{
			ft_free_char(av2);
			return (0);
		}
	}
	ft_free_char(av2);
	return (1);
}

void	read_line(t_stack **stack_a, t_stack **stack_b)
{
	char	*getter;

	while (1)
	{
		getter = get_next_line(0);
		if (!getter)
			break ;
		operations_bonus(stack_a, stack_b, getter);
		free(getter);
	}
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	static int	row;
	static int	col;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2 || !ft_strlen(av[1]))
		return (0);
	if (!check(ac, av, row, col))
		ft_error(&stack_a);
	stack_a = execute(ac, av);
	if (!is_dup(stack_a))
		ft_error(&stack_a);
	if (stack_a && !is_sorted(&stack_a))
		read_line(&stack_a, &stack_b);
	response(is_sorted(&stack_a), &stack_b);
	ft_free_stack(&stack_a);
}
