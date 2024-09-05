/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabi-aka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 12:27:03 by rabi-aka          #+#    #+#             */
/*   Updated: 2024/08/18 15:08:39 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_case(int i, int j, int x, int y)
{
	if (i == 0 && j == 0)
		ft_putchar('/');
	else if (i == x - 1 && j == 0)
		ft_putchar('\\');
	else if (i == 0 && j == y - 1)
		ft_putchar('\\');
	else if (i == x - 1 && j == y - 1)
		ft_putchar('/');
	else if (j == 0 || j == y - 1 || i == 0 || i == x - 1)
		ft_putchar('*');
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
		i = 0;
		ft_putchar('\n');
		j = j + 1;
	}
}
