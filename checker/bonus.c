/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinosoares <justinosoares@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:46:36 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/19 22:40:58 by justinosoar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	find_newline(const char *s)
{
	int i = 0;

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
	char		*line = NULL;
	int			bytes_read;
	int			newline_index;

	while (1)
	{
		if ((newline_index = find_newline(buffer)) >= 0)
		{
			line = strndup(buffer, newline_index + 1);
			memmove(buffer, buffer + newline_index + 1, strlen(buffer) - newline_index);
			break ;
		}
		else if ((bytes_read = read(fd, buffer + strlen(buffer), BUFFER_SIZE - strlen(buffer))) <= 0)
		{
			if (strlen(buffer) > 0 )
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

char	*append_buffer(char *dest, char *src, ssize_t len)
{
	char	*new_str;
	size_t	dest_len;

	if (!dest)
		dest_len = 0;
	else
		dest_len = strlen(dest);
	new_str = malloc(dest_len + len + 1);
	if (!new_str)
		return (NULL);
	if (dest)
	{
		strcpy(new_str, dest);
		free(dest);
	}
	memcpy(new_str + dest_len, src, len);
	new_str[dest_len + len] = '\0';
	return (new_str);
}

char	**read_data(void)
{
	char **getter;
///	char *data = NULL;
	int	i;

	i = 0;
	getter = ft_split(" ");
	while (get_next_line(0))
	{
		/*getter[i] = strdup(get_next_line(0));
		data = append_buffer(data, getter[i], strlen(getter[i]));
		if (!data)
			return (NULL); 
		*/
		printf("get :%s\n", get_next_line(0));
		i++; 
	}
	return (getter);
}

static void	operations(t_stack **stack_a, t_stack **stack_b, char **getter)
{
	int	i;

	i = 0;
	while (getter[i])
	{
		if (!ft_strcmp(getter[i], "sa"))
			swap(stack_a, '\0');
		else if (!ft_strcmp(getter[i], "rra"))
			rr_ab(stack_a, '\0');
		else if (!ft_strcmp(getter[i], "rrb"))
			rr_ab(stack_b, '\0');
		else if (!ft_strcmp(getter[i], "ra"))
			rotate(stack_a, '\0');
		else if (!ft_strcmp(getter[i], "rb"))
			rotate(stack_b, '\0');
		else if (!ft_strcmp(getter[i], "rr"))
			rr(stack_a, stack_b);
		else if (!ft_strcmp(getter[i], "rrr"))
			rrr(stack_a, stack_b);
		else if (!ft_strcmp(getter[i], "pb"))
			push(stack_a, stack_b, '\0');
		else if (!ft_strcmp(getter[i], "pa"))
			push(stack_b, stack_a, '\0');
		printf("%s", getter[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**getter;
	int	row;
	int	col;

	row = 0;
	col = 0;
	stack_a = NULL;
	stack_b = NULL;

	stack_a = execute(ac, av);
	if (stack_a && !is_sorted(&stack_a) && ac >= 2)
	{
		getter = read_data();
		if (!is_all_right(stack_a, av, row, col))
			ft_error();
		operations(&stack_a, &stack_b, getter);
		if (is_sorted(&stack_a) && stack_b == NULL)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
}
