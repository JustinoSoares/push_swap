/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:44:09 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/27 13:23:22 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*execute(int ac, char **av)
{
	char	**av2;
	int		i;
	t_stack	*stack_a;

	stack_a = NULL;
	av2 = ft_split(av[1]);
	if (ac == 2)
	{
		i = 0;
		while (av2[i])
		{
			append_end(&stack_a, ft_atoi_free(av2[i], &stack_a, av2));
			i++;
		}
		ft_free_char(av2);
	}
	else
	{
		i = 1;
		while (i < ac)
			append_end(&stack_a, ft_atoi_free(av[i++], &stack_a, av2));
		ft_free_char(av2);
	}
	return (stack_a);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	if (!is_sorted(stack_a))
	{
		if (stack_size(*stack_a) > 3)
			sort_any(stack_a, stack_b);
		else
			sort_3(stack_a);
	}
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

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	static int	row;
	static int	col;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	if (!ft_strlen(av[1]) || ft_is_only_space(av[1]))
		ft_error2();
	if (check(ac, av, row, col) == 0)
	{
		ft_error2();
		return (0);
	}
	stack_a = execute(ac, av);
	if (!is_dup(stack_a))
	{
		ft_error(&stack_a);
		return (0);
	}
	sort(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	return (0);
}
