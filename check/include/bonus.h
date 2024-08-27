/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:28:39 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/27 10:41:52 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1234
# endif

# include "../../srcs/push_swap.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_aux_get
{
	char	*line;
	int		bytes_read;
	int		newline_index;
}			t_aux_get;

char		*get_next_line(int descritor_arquivo);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ler_primeira_linha(int descritor_arquivo, char *texto);
char		*obter_linha(char *texto);
char		*limpar_primeira_linha(char *texto);
void		*ft_calloc(unsigned int count, unsigned int size);
void		ft_bzero(void *s, unsigned int n);

t_stack		*execute(int ac, char **av);
int			ft_strcmp(char *s1, char *s2);
void		rrr_bonus(t_stack **stack_a, t_stack **stack_b);
void		rr_bonus(t_stack **stack_a, t_stack **stack_b);
void		push_bonus(t_stack **stack_from, t_stack **stack_to);
t_stack		*execute(int ac, char **av);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_strndup(const char *s, int len);
char		*ft_strdup(const char *s);
void		operations_bonus(t_stack **stack_a, t_stack **stack_b,
				char *getter);
#endif