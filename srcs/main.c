/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:44:09 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/19 12:48:31 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*execute(int ac, char **av)
{
	char	**av2;
	int		i;
	t_stack	*stack_a;

	stack_a = NULL;
	if (ac == 2)
	{
		i = 0;
		av2 = ft_split(av[1]);
		while (av2[i])
		{
			append_end(&stack_a, ft_atoi(av2[i]));
			i++;
		}
	}
	else
	{
		i = 1;
		while (i < ac)
			append_end(&stack_a, ft_atoi(av[i++]));
	}
	return (stack_a);
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
		return (write(1, "", 1));
	stack_a = execute(ac, av);
	if (!is_all_right(stack_a, av, row, col))
		ft_error();
	if (!is_sorted(&stack_a))
	{
		if (stack_size(stack_a) > 3)
			sort_any(&stack_a, &stack_b);
		else
			sort_3(&stack_a);
	}
}
