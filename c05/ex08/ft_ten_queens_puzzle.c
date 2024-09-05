/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:25:50 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/19 15:29:41 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_sol(int *sol)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = '0' + sol[i];
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

unsigned int	ft_abs(int a)
{
	if (a >= 0)
		return (a);
	else
		return (-a);
}

int	ft_is_free(int *sol, int i, int j)
{
	int	l;
	int	c;

	l = 0;
	while (l < i)
	{
		if (l != i)
		{	
			c = sol[l];
			if (j == c || (ft_abs(i - l) == ft_abs (j - c)))
				return (0);
		}	
		l++;
	}
	return (1);
}

void	ft_place_queen(int *sol, int l, int *ret)
{
	int	c;

	if (l >= 10)
	{
		ft_print_sol(sol);
		*ret += 1;
	}
	else
	{
		c = 0;
		while (c < 10)
		{
			if (ft_is_free(sol, l, c))
			{
				sol[l] = c;
				ft_place_queen(sol, l + 1, ret);
			}
			c++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	sol[10];
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (i < 10)
	{
		sol[i] = -1;
		i++;
	}
	ft_place_queen(sol, 0, &ret);
	return (ret);
}
