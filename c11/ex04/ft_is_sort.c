/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:22:21 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/29 03:06:05 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_croissant(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 1;
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_decroissant(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 1;
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	return (ft_check_croissant(tab, length, f) || ft_check_decroissant(tab,
			length, f));
}
