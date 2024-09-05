/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:17:39 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/14 22:04:02 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr3(char c1, char c2, char c3)
{
	char	str[5];

	str[0] = c1;
	str[1] = c2;
	str[2] = c3;
	str[3] = ',';
	str[4] = ' ';
	write (1, str, 5);
	return ;
}

void	ft_increment(char *c1, char *c2, char *c3)
{
	if (c3[0] == '9')
	{
		if (c2[0] == '8')
		{
			c1[0] = c1[0] + 1;
			c2[0] = c1[0] + 1;
			c3[0] = c1[0] + 2;
		}
		else
		{
			c2[0] = c2[0] + 1;
			c3[0] = c2[0] + 1;
		}
	}
	else
	{
		c3[0] = c3[0] + 1;
	}
	return ;
}

void	ft_print_comb(void)
{
	char	c1;
	char	c2;
	char	c3;

	c1 = '0';
	c2 = '1';
	c3 = '2';
	while (!(c1 == '7' && c2 == '8' && c3 == '9'))
	{
		ft_putnbr3(c1, c2, c3);
		ft_increment(&c1, &c2, &c3);
	}
	write (1, "789", 3);
	return ;
}
