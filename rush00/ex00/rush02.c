/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 11:52:51 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/17 12:56:24 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_case(int i, int j, int x, int y)
{
	if ((i == 0 && j == 0) || (j == 0 && i == x - 1))
		ft_putchar('A');
	else if ((j == y - 1 && i == 0) || (j == y - 1 && i == x - 1))
		ft_putchar('C');
	else if (j == 0 || j == y - 1 || i == 0 || i == x - 1)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (x == 0 || y == 0)
		return ;
	while (j < y)
	{
		while (i < x)
		{
			ft_print_case(i, j, x, y);
			i += 1;
		}
		ft_putchar('\n');
		i = 0;
		j = j + 1;
	}
}
