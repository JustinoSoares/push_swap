/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:34:11 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/27 08:59:19 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	is_digit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	return (0);
}

int	is_space(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	check_error(char **av, int row, int col)
{
	while (av[row])
	{
		col = 0;
		if (ft_atoi(av[row]) >= 2147483647 || ft_atoi(av[row]) <= -2147483648)
			return (0);
		while ((av[row][col] != '\0'))
		{
			if (av[row][col] == '\0')
				break ;
			if (is_sign(av[row][col]))
			{
				col++;
				if (!is_digit(av[row][col]))
					return (0);
			}
			else if (!is_digit(av[row][col]) && !is_space(av[row][col]))
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

int	is_dup(t_stack *stack)
{
	t_stack	*getter;

	while (stack)
	{
		getter = stack->next;
		while (getter)
		{
			if (stack->num == getter->num)
				return (0);
			getter = getter->next;
		}
		stack = stack->next;
	}
	return (1);
}
