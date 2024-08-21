/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasta2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:32:14 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/20 11:46:47 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus.h"

void	rrr_bonus(t_stack **stack_a, t_stack **stack_b)
{
	rr_ab(stack_a, '\0');
	rr_ab(stack_b, '\0');
}

void	rr_bonus(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, '\0');
	rotate(stack_b, '\0');
}

void	push_bonus(t_stack **stack_from, t_stack **stack_to)
{
	int	top;

	top = (*stack_from)->num;
	pop_start(stack_from);
	append_start(stack_to, top);
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
	}
	else
	{
		i = 1;
		while (i < ac)
			append_end(&stack_a, ft_atoi(av[i++]));
	}
	return (stack_a);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
