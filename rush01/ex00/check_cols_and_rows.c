/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cols_and_rows.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:17:03 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/25 10:17:05 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_row_right(int i, char **sol, char **pb, int n)
{
	int	j;
	int	count;
	int	max;

	j = n - 1;
	count = 1;
	max = sol[i][j];
	while (j >= 0)
	{
		if (sol[i][j] > max)
		{
			max = sol[i][j];
			count++;
		}
		j--;
	}
	if (count != pb[3][i] - '0')
		return (0);
	return (1);
}

int	check_row_left(int i, char **sol, char **pb, int n)
{
	int	j;
	int	count;
	int	max;

	j = 0;
	count = 1;
	max = sol[i][0];
	while (j < n)
	{
		if (sol[i][j] > max)
		{
			count++;
			max = sol[i][j];
		}
		j++;
	}
	if (count != pb[2][i] - '0')
		return (0);
	return (1);
}

int	check_col_up(int j, char **sol, char **pb, int n)
{
	int	i;
	int	count;
	int	max;

	i = 0;
	count = 1;
	max = sol[i][j];
	while (i < n)
	{
		if (sol[i][j] > max)
		{
			max = sol[i][j];
			count++;
		}
		i++;
	}
	if (count != pb[0][j] - '0')
		return (0);
	return (1);
}

int	check_col_down(int j, char **sol, char **pb, int n)
{
	int	i;
	int	count;
	int	max;

	i = n - 1;
	count = 1;
	max = sol[i][j];
	while (i >= 0)
	{
		if (sol[i][j] > max)
		{
			max = sol[i][j];
			count++;
		}
		i--;
	}
	if (count != pb[1][j] - '0')
		return (0);
	return (1);
}
