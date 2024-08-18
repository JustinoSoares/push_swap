/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:44:09 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/18 14:11:42 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char *av[])
{
    int i;
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;

    i = 1;
    while (i < ac)
    {
        append_end(&stack_a, atoi(av[i]));
        i++;
    }
    if (stack_size(stack_a) > 3)
        sort_any(&stack_a, &stack_b);
    else
        sort_3(&stack_a);
    //printf("Stack A\n");
    //ft_write(stack_a);
   // printf("Stack B\n");
    //ft_write(stack_b);
}