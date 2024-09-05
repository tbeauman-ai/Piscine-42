/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 10:44:48 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/27 12:58:38 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!base)
		return (0);
	while (base[i])
	{
		j = 0;
		if (base[i] == '+' || base[i] == '-' || \
			(base[i] >= 9 && base[i] < 13) || base[i] == ' ')
			return (0);
		while (base[j])
		{
			if (base[j] == base[i] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base_long(long nb, char *base)
{
	int	len_base;

	len_base = check_base(base);
	if (len_base <= 1)
		return ;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb / len_base)
		ft_putnbr_base_long(nb / len_base, base);
	write(1, &base[nb % len_base], 1);
}

void	ft_putnbr_base(int nb, char *base)
{
	ft_putnbr_base_long((long)nb, base);
}
