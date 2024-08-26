/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:34:11 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/26 19:05:36 by jsoares          ###   ########.fr       */
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

int	check_error(char **argv, int row, int col)
{
	row = 1;
	while (argv[row])
	{
		col = 0;
		while ((argv[row][col] != '\0'))
		{
			if (argv[row][col] == '\0')
				break ;
			if (is_sign(argv[row][col]))
			{
				col++;
				if (!is_digit(argv[row][col]))
					return (0);
			}
			else if (!is_digit(argv[row][col]) && !is_space(argv[row][col]))
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
