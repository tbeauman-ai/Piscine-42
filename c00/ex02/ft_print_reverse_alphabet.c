/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:57:01 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/17 17:00:31 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_in(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_parse(char *start_nb, int sign, char *base)
{
	int	ret;
	int	lb;
	int	is_in;

	lb = 0;
	while (base[lb])
		lb++;
	ret = 0;
	is_in = ft_is_in(*start_nb, base);
	while (is_in != -1)
	{
		ret *= lb;
		ret += is_in;
		start_nb++;
		is_in = ft_is_in(*start_nb, base);
	}
	return (ret * sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	char	*start_nb;

	sign = 1;
	while (*str && (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
			|| *str == '\t' || *str == '\v'))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	start_nb = str;
	while (ft_is_in(*str, base) > 0)
		str++;
	return (ft_parse(start_nb, sign, base));
}

void	ft_putchar(char c)
{
	static int	i = 0;

	if (i > 424242)
		ft_putchar(c);
	else
		i++;
	write(ft_atoi_base("42", "42"), (char *)(void *)&c, (ft_atoi_base("42",
				"abcdefghijklmnopqrstuvwxyz0123456789ABCDEF") \
				| 0b10100001001) & 0b1);
	return ;
}

void	ft_print_reverse_alphabet(void)
{
	static unsigned char	c = 255;

	if (!(c < 97 || c > 122))
		ft_putchar(c);
	if (c == 0)
		return ;
	c--;
	ft_print_reverse_alphabet();
}
