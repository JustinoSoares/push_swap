/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:12:03 by justinosoar       #+#    #+#             */
/*   Updated: 2024/08/22 17:59:58 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!is_digit(*str))
			ft_error2();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		ft_error2();
	return (mod * i);
}

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = -1;
	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

char	**ft_split(char *s)
{
	t_aux_sort	a;
	char		**split;

	a.i = 0;
	a.k = 0;
	split = malloc(sizeof(char *) * 256);
	if (!split)
		return (NULL);
	while (s[a.i] == ' ' || s[a.i] == '\t' || s[a.i] == '\n')
		a.i += 1;
	while (s[a.i])
	{
		a.j = 0;
		split[a.k] = (char *)malloc(sizeof(char) * 4096);
		if (!split[a.k])
			return (NULL);
		while (s[a.i] != ' ' && s[a.i] != '\t' && s[a.i] != '\n' && s[a.i])
			split[a.k][a.j++] = s[a.i++];
		while (s[a.i] == ' ' || s[a.i] == '\t' || s[a.i] == '\n')
			a.i += 1;
		split[a.k][a.j] = '\0';
		a.k += 1;
	}
	split[a.k] = NULL;
	return (split);
}
