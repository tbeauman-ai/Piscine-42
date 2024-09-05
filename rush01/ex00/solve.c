/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:16:16 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/25 10:17:36 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		is_sol(char *sol[4], char **pb, int n);
void	print_sol(char **sol, int n);

int	test_backtrack(char **sol, int pos, char k, int n)
{
	int	i;
	int	j;

	j = 0;
	while (j < pos % n)
	{
		if (sol[pos / n][j] == k + '0')
			return (0);
		j++;
	}
	i = 0;
	while (i < pos / n)
	{
		if (sol[i][pos % n] == k + '0')
			return (0);
		i++;
	}
	return (1);
}

int	solve(char **sol, char **pb, int pos, int n)
{
	int	k;

	if (pos == n * n && is_sol(sol, pb, n))
	{
		print_sol(sol, n);
		return (1);
	}
	else if (pos == n * n)
		return (0);
	k = 1;
	while (k <= n)
	{
		if (test_backtrack(sol, pos, k, n))
		{
			sol[pos / n][pos % n] = k + '0';
			if (solve(sol, pb, pos + 1, n))
				return (1);
		}
		k++;
	}
	return (0);
}
