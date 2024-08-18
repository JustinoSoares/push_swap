/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinosoares <justinosoares@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 06:43:57 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/18 23:20:32 by justinosoar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define SIZE_TAB 6
# define TARGET 0
#define  DEST 1
#define INDEX_A 2
#define INDEX_B 3
#define COST 4
#define IS_DUPLE 5
typedef struct s_stack
{
    int num;
    struct s_stack *next;
}   t_stack;

typedef struct s_aux_sort
{
    int row;
    int opt_a;
    int opt_b;
    int index_cheaper;
    int send_without_verify;
    int cont;
    int getter;
    int aux_cost;
    int is_duple;
}   t_aux_sort;


void    swap(t_stack **stack, char ab);
void    rotate(t_stack **stack, char ab);
void    allocate_error(t_stack **stack);
void    ft_write(t_stack *stack);
void    append_end(t_stack **stack, int num);
void    append_start(t_stack **stack, int num);
void    pop_start(t_stack **stack);
int stack_size(t_stack *stack);
void    push(t_stack **stack_from, t_stack **stack_to, char ab);
int max_value(t_stack *stack);
int min_value(t_stack *stack);
int next_max(t_stack *stack, int num);
int next_min(t_stack *stack, int num);
int is_sorted(t_stack **stack);
void    sort_3(t_stack **stack);
void    sort_any(t_stack **stack_a, t_stack **stack_b);
int get_index(t_stack *stack, int num);
int ft_index_cheaper(int **tab);
void    put_on_top_a(t_stack **stack_a, int index_a);
void    put_on_top_b(t_stack **stack_b, int index_b);
void    put_on_top(t_stack **stack_a, int index_a, t_stack **stack_b, int index_b);
void    rr_ab(t_stack **stack, char ab);
void    rrr(t_stack **stack_a, t_stack **stack_b);
void    rr(t_stack **stack_a, t_stack **stack_b);
int index_less(int a, int b);
int piv(t_stack **stack);
void    sort_big(t_stack **stack_a, t_stack **stack_b);
int last_num(t_stack **stack);
void    selection(t_stack **stack_a, t_stack **stack_b);
void    ft_error(void);
int is_dup(t_stack *stack);
int	check_error(char **argv, int i, int j);
int	ft_atoi(const char *str);
int	is_digit(int c);

#endif