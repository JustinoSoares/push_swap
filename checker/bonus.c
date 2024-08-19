/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:46:36 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/19 16:36:06 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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
	char	buffer[100];
	ssize_t	bytes_read;
	char	*data;
	char	**getter;

	data = NULL;
	getter = NULL;
	while ((bytes_read = read(0, buffer, sizeof(buffer) - 1)) > 0)
	{
		buffer[bytes_read] = '\0';
		data = append_buffer(data, buffer, bytes_read);
		if (!data)
			return (NULL);
	}
	if (bytes_read == -1)
	{
		free(data);
		return (NULL);
	}
	getter = ft_split(data);
	free(data);
	return (getter);
}

static void	operations(t_stack **stack_a, t_stack **stack_b, char **getter)
{
	int	i;

	(void)stack_a;
	(void)stack_b;
	i = 0;
	while (getter[i])
	{
		/*if (!ft_strcmp(getter[i], "sa"))
			swap(stack_a, 'a');
		else if (!ft_strcmp(getter[i], "rra"))
			rr_ab(stack_a, 'a');
		else if (!ft_strcmp(getter[i], "rrb"))
			rr_ab(stack_b, 'b');
		else if (!ft_strcmp(getter[i], "ra"))
			rotate(stack_a, 'a');
		else if (!ft_strcmp(getter[i], "rb"))
			rotate(stack_b, 'b');
		else if (!ft_strcmp(getter[i], "rr"))
			rr(stack_a, stack_b);
		else if (!ft_strcmp(getter[i], "rrr"))
			rrr(stack_a, stack_b);
		else if (!ft_strcmp(getter[i], "pb"))
			push(stack_a, stack_b, 'b');
		else if (!ft_strcmp(getter[i], "pa"))
			push(stack_b, stack_a, 'a'); */
		printf("%s\n", getter[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**getter;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = execute(ac, av);
	getter = read_data();
	operations(&stack_a, &stack_b, getter);
	if (is_sorted(&stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	// ft_write(stack_a);
	// ft_write(stack_b);
}
