/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 06:43:57 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/08 13:15:05 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
    int num;
    struct s_stack *next;
}   t_stack;

void    sa(t_stack **stack);
void    sb(t_stack **stack);
void    ra(t_stack **stack);
void    error(t_stack *stack);
void    ra(t_stack **stack);
void    allocate_error(void);
void    ft_write(t_stack *stack);
void    pop_end(t_stack **stack, int num);
int stack_size(t_stack *stack);

#endif