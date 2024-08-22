/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:28:54 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/22 14:30:23 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus.h"

void	operations_bonus(t_stack **stack_a, t_stack **stack_b, char *getter)
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
