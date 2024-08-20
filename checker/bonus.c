/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:46:36 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/20 11:30:55 by jsoares          ###   ########.fr       */
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

// Função que lê linha por linha e retorna a próxima linha.
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;
	int			newline_index;

	line = NULL;
	while (1)
	{
		if ((newline_index = find_newline(buffer)) >= 0)
		{
			line = strndup(buffer, newline_index + 1);
			memmove(buffer, buffer + newline_index + 1, strlen(buffer)
				- (newline_index - 1));
			break ;
		}
		else if ((bytes_read = read(fd, buffer + strlen(buffer), BUFFER_SIZE
					- strlen(buffer))) <= 0)
		{
			if (strlen(buffer) > 0)
				line = strdup(buffer);
			else
				line = NULL;
			buffer[0] = '\0';
			break ;
		}
		buffer[bytes_read] = '\0';
	}
	return (line);
}

static void	operations(t_stack **stack_a, t_stack **stack_b, char *getter)
{
	if (!ft_strcmp(getter, "sa\n"))
		swap(stack_a, '\0');
	if (!ft_strcmp(getter, "sb\n"))
		swap(stack_b, '\0');
	else if (!ft_strcmp(getter, "rra\n"))
		rr_ab(stack_a, '\0');
	else if (!ft_strcmp(getter, "rrb\n"))
		rr_ab(stack_b, '\0');
	else if (!ft_strcmp(getter, "ra\n"))
		rotate(stack_a, '\0');
	else if (!ft_strcmp(getter, "rb\n"))
		rotate(stack_b, '\0');
	else if (!ft_strcmp(getter, "rr\n"))
		rr_bonus(stack_a, stack_b);
	else if (!ft_strcmp(getter, "rrr\n"))
		rrr_bonus(stack_a, stack_b);
	else if (!ft_strcmp(getter, "pb\n"))
		push_bonus(stack_a, stack_b);
	else if (!ft_strcmp(getter, "pa\n"))
		push_bonus(stack_b, stack_a);
	else if (!ft_strcmp(getter, "pa"))
		push_bonus(stack_b, stack_a);
	else if (!ft_strcmp(getter, "p"))
		push_bonus(stack_b, stack_a);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*getter;
	int		row;
	int		col;

	row = 0;
	col = 0;
	stack_a = NULL;
	stack_b = NULL;
	stack_a = execute(ac, av);
	if (stack_a && !is_sorted(&stack_a) && ac >= 2)
	{
		if (!is_all_right(stack_a, av, row, col))
			ft_error();
		while (1)
		{
			getter = get_next_line(0);
			if (!getter)
				break ;
			operations(&stack_a, &stack_b, getter);
			free(getter);
		}
		if (is_sorted(&stack_a) && stack_b == NULL)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
}
