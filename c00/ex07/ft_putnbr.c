/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:22:26 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/14 22:04:53 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_len_int(int nb)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	first_digit(int nb, int len)
{
	int	tmp;

	tmp = nb;
	while (len > 1)
	{
		tmp = tmp / 10;
		len--;
	}
	return (tmp);
}

int	ft_pow(int n, int p)
{
	int	r;

	r = 1;
	while (p > 0)
	{
		p--;
		r = n * r;
	}
	return (r);
}

int	ft_process(int nb)
{
	char	c;
	int		i;
	int		fd;

	i = ft_len_int(nb);
	fd = first_digit(nb, i);
	c = '0' + fd;
	write(1, &c, 1);
	nb = nb - ft_pow(10, i - 1) * fd;
	while (first_digit(nb, i - 1) == 0 && i > 1)
	{
		write(1, "0", 1);
		i = i - 1;
	}
	return (nb);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	else if (nb == 0)
	{
		write (1, "0", 1);
	}
	while (nb > 0)
	{
		nb = ft_process(nb);
	}	
	return ;
}
