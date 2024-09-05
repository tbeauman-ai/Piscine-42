/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:14:58 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/28 22:15:17 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	get_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = get_size(tab) - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (cmp(tab[j + 1], tab[j]) < 0)
				ft_swap(&(tab[j + 1]), &(tab[j]));
			j++;
		}
		i--;
	}
}
