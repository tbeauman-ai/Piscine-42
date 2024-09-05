/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 07:45:11 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/24 08:00:54 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);

void	print_sol(char **sol, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			ft_putchar(sol[i][j]);
			if (j < n - 1)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	print_pb(char **pb, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (i == 0)
			ft_putstr("COLUP    :");
		if (i == 1)
			ft_putstr("COLDOWN  :");
		if (i == 2)
			ft_putstr("ROWLEFT  :");
		if (i == 3)
			ft_putstr("ROWRIGHT :");
		j = 0;
		while (j < n)
		{
			ft_putchar(pb[i][j]);
			if (j < n - 1)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
