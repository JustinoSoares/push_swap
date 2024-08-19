/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:46:51 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/19 15:48:30 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "../srcs/push_swap.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strcmp(char *s1, char *s2);
char	**read_data(void);
t_stack	*execute(int ac, char **av);

#endif