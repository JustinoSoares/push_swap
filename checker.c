/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinosoares <justinosoares@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:34:11 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/18 23:20:02 by justinosoar      ###   ########.fr       */
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


int	check_error(char **argv, int i, int j)
{
    i = 1;
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j] != '\0'))
		{
            if (argv[i][j] == '\0')
					break ;
			if (is_sign(argv[i][j]))
			{
				j++;
				if (!is_digit(argv[i][j]))
					return (0);
			}
			else if (!is_digit(argv[i][j]) && !is_space(argv[i][j]))
                return (0);
			j++;
		}
		i++;
	}
	return (1);
}


int is_dup(t_stack *stack)
{
    t_stack *getter;
    
    while(stack)
    {
        getter = stack->next;
        while (getter)
        {
            if (stack->num == getter->num)
                return(0);
            getter = getter->next;
        }
        stack = stack->next;
    }
    return (1);
}
