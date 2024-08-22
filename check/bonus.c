/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:46:36 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/22 14:29:42 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus.h"

static int	find_newline(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*read_line(char *buffer)
{
	char	*line;

	if (ft_strlen(buffer) > 0)
		line = ft_strdup(buffer);
	else
		line = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	t_aux_get	aux_get;

	aux_get.line = NULL;
	while (1)
	{
		aux_get.newline_index = find_newline(buffer);
		aux_get.bytes_read = read(fd, buffer + ft_strlen(buffer), BUFFER_SIZE
				- ft_strlen(buffer));
		if (aux_get.newline_index >= 0)
		{
			aux_get.line = ft_strndup(buffer, aux_get.newline_index + 1);
			ft_memmove(buffer, buffer + aux_get.newline_index + 1,
				ft_strlen(buffer) - (aux_get.newline_index - 1));
			break ;
		}
		else if (aux_get.bytes_read <= 0)
		{
			aux_get.line = read_line(buffer);
			buffer[0] = '\0';
			break ;
		}
		buffer[aux_get.bytes_read] = '\0';
	}
	return (aux_get.line);
}

void	response(int is_sort, t_stack *stack)
{
	if (is_sort && stack == NULL)
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
		response(is_sorted(&stack_a), stack_b);
	}
}
