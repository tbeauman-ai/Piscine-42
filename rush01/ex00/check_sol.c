/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 07:57:48 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/24 08:26:35 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	check_row_right(int i, char **sol, char **pb, unsigned int n);
int	check_row_left(int i, char **sol, char **pb, unsigned int n);
int	check_col_up(int j, char **sol, char **pb, unsigned int n);
int	check_col_down(int j, char **sol, char **pb, unsigned int n);

int	is_sol(char **sol, char **pb, int n)
{
	int	k;

	k = 0;
	while (k < n)
	{
		if (!(check_row_right(k, sol, pb, n) && check_col_up(k, sol, pb, n)
				&& check_row_left(k, sol, pb, n) && check_col_down(k, sol, pb,
					n)))
			return (0);
		k++;
	}
	return (1);
}
