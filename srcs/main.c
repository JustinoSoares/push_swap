/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:44:09 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/22 12:20:51 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_char(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

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
		ft_free_char(av2);
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
		return (0);
	if (!check_error(av, row, col))
	{
		ft_error(&stack_a);
		return (0);
	}
	stack_a = execute(ac, av);
	if (!is_sorted(&stack_a))
	{
		if (stack_size(stack_a) > 3)
			sort_any(&stack_a, &stack_b);
		else
			sort_3(&stack_a);
	}
	ft_free_stack(&stack_a);
	return (0);
}
