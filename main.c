/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinosoares <justinosoares@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:44:09 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/10 22:17:21 by justinosoar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char *av[])
{
    int i = 1;
    int op;
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;
    
    while (1)
    {
        printf("digite: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("stack a\n");
            ft_write(stack_a);
            printf("stack b\n");
            ft_write(stack_b);
            break;
        case 2:
            while (i < ac)
            {
                append_end(&stack_a, atoi(av[i]));
                i++;
            }
            break;
        case 3:
            printf("size: %d\n", stack_size(stack_a));
            break;
        case 4:
            sort_any(&stack_a, &stack_b);
        default:
            break;
        }
    }
    
}