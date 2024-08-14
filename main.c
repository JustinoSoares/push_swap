/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinosoares <justinosoares@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:44:09 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/14 00:36:02 by justinosoar      ###   ########.fr       */
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
    sort_any(&stack_a, &stack_b);
    
   // printf("Stack A\n");
    //ft_write(stack_a);
    //printf("Stack B\n");
    //ft_write(stack_b);
}