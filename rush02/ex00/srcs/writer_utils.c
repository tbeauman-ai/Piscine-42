/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:05:04 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/31 20:05:06 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"

char	*trim_zeroes(char *n)
{
	char	*trim;
	int		i;

	while (*n == '0')
		n++;
	trim = (char *)malloc(ft_strlen(n) + 1);
	if (!trim)
		return (0);
	i = 0;
	while (*n)
	{
		trim[i] = *n;
		i++;
		n++;
	}
	trim[i] = 0;
	return (trim);
}

void	print_found_with_space(char *found)
{
	ft_putstr(found);
	ft_putstr(" ");
}

int	is_last_paquet(t_number *nb)
{
	nb = nb->next;
	while (nb)
	{
		if (ft_atoi(nb->str) != 0)
			return (0);
		nb = nb->next;
	}
	return (1);
}

int	is_positive_integer(char *number)
{
	if (!*number)
		return (0);
	while (*number)
	{
		if (!(*number >= '0' && *number <= '9'))
			return (0);
		number++;
	}
	return (1);
}

t_dict	*find_in_dico(char *nb_dg, t_dict *dico)
{
	while (dico)
	{
		if (!ft_strcmp(nb_dg, dico->nb_digits))
			return (dico);
		dico = dico->next;
	}
	return (dico);
}
