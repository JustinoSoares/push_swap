/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:16:36 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/19 15:47:48 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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
