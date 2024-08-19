/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinosoares <justinosoares@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:55:33 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/18 19:56:49 by justinosoar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_error(void)
{
    write(1, "Error\n", 6);
    exit(1);
}

void    ft_free(t_stack **stack)
{
        t_stack *tmp;

        if (!stack)
                return ;
        while (*stack)
        {
                tmp = (*stack)->next;
                tmp->num = 0;
                free(*stack);
                *stack = tmp;
        }
}

void    allocate_error(t_stack **stack)
{
        fprintf(stderr, "Erro ao alocar memória\n");
        ft_free(stack);
        exit(1);
}