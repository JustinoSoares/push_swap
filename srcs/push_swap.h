/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 06:43:57 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/27 14:37:32 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SIZE_TAB 5
# define TARGET 0
# define DEST 1
# define INDEX_A 2
# define INDEX_B 3
# define COST 4

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

typedef struct s_aux_sort
{
	int				row;
	int				opt_a;
	int				opt_b;
	int				index_cheaper;
	int				send_without_verify;
	int				cont;
	int				getter;
	int				aux_cost;
	int				is_duple;
	int				i;
	int				j;
	int				k;
}					t_aux_sort;

void				swap(t_stack **stack, char ab);
void				rotate(t_stack **stack, char ab);
void				append_end(t_stack **stack, int num);
void				append_start(t_stack **stack, int num);
void				pop_start(t_stack **stack);
int					stack_size(t_stack *stack);
void				push(t_stack **stack_from, t_stack **stack_to, char ab);
int					max_value(t_stack *stack);
int					min_value(t_stack *stack);
int					next_max(t_stack *stack, int num);
int					next_min(t_stack *stack, int num);
int					is_sorted(t_stack **stack);
void				sort_3(t_stack **stack);
void				sort_any(t_stack **stack_a, t_stack **stack_b);
int					get_index(t_stack *stack, int num);
int					ft_index_cheaper(int **tab, int len);
void				put_on_top_a(t_stack **stack_a, int index_a);
void				put_on_top_b(t_stack **stack_b, int index_b);
void				put_on_top(t_stack **stack_a, int index_a,
						t_stack **stack_b, int index_b);
void				rr_ab(t_stack **stack, char ab);
void				rrr(t_stack **stack_a, t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
int					index_less(int a, int b);
void				ft_error(t_stack **stack);
void				ft_error2(void);
int					is_dup(t_stack *stack);
int					check_error(char **argv, int row, int col);
int					ft_atoi(const char *str);
int					ft_atoi_free(const char *str, t_stack **stack_a,
						char **av2);
int					is_digit(int c);
char				**ft_split(char *str);
void				ft_free(t_stack **stack);
void				free_matriz(int **tab, int row);
void				ft_free_char(char **str);
void				ft_free_stack(t_stack **stack);
void				ft_free_dup(t_stack **stack_a, t_stack **stack_b);
void				free_tab(int **tab, t_stack *stack);
int					*calc_cost_goo_a(int *tab, t_stack **stack_a,
						t_stack **stack_b, t_stack *tmp_b);
void				sort_goo_a(t_stack **stack_a, t_stack **stack_b);
void				get_cost_a(int **tab, t_stack **stack_a, t_stack **stack_b,
						t_stack *tmp_a);
int					get_cost_rr(int opt_a, int opt_b, int getter);
int					*calc_cost_goo_b(int *tab, t_stack **stack_a,
						t_stack **stack_b, t_stack *tmp_a);
void				sort_goo_b(t_stack **stack_a, t_stack **stack_b);
void				get_cost_b(int **tab, t_stack **stack_a, t_stack **stack_b,
						t_stack *tmp_b);
int					ft_index_cheaper(int **tab, int len);
void				ft_send_without_verify(t_stack **stack_a,
						t_stack **stack_b);
int					cheaper(int first, int second);
int					is_sort_3(t_stack **stack);
int					ft_strlen(const char *s);
int					ft_is_only_space(char *str);

#endif