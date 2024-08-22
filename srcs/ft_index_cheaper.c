/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_cheaper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:11:30 by jsoares           #+#    #+#             */
/*   Updated: 2024/08/22 18:11:56 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_index_cheaper(int **tab, int len)
{
	int	cont;
	int	cost;
	int	index;

	cont = 0;
	index = 0;
	if (!tab)
		return (-1);
	cost = tab[0][COST];
	while (cont < len)
	{
		if (cost > tab[cont][COST])
		{
			cost = tab[cont][COST];
			index = cont;
		}
		cont++;
	}
	return (index);
}
