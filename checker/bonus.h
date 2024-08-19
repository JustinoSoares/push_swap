/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinosoares <justinosoares@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:46:51 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/19 21:59:01 by justinosoar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# define BUFFER_SIZE 1024

# include "../srcs/push_swap.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int		ft_strcmp(char *s1, char *s2);
char	**read_data(void);
t_stack	*execute(int ac, char **av);

#endif