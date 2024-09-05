/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:45:08 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/19 21:50:52 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_len_base(char *b)
{
	int	i;

	i = 0;
	while (b[i])
		i++;
	return (i);
}

long	ft_is_in(char c, char *base)
{
	long	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

long	ft_parse(char *start_nb, long sign, char *base)
{
	long	ret;
	long	lb;
	long	is_in;

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

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (!base)
		return (0);
	while (base[++i])
	{
		j = 0;
		if (base[i] == '+' || base[i] == '-' || !(base[i] >= 32
				&& base[i] <= 126) || base[i] == ' ' || base[i] == '\f'
			|| base[i] == '\n' || base[i] == '\r' || base[i] == '\t'
			|| base[i] == '\v')
			return (0);
		while (base[++j])
			if (base[j] == base[i] && i != j)
				return (0);
	}
	if (i <= 1)
		return (0);
	return (i);
}

long	ft_atol_base(char *str, char *base)
{
	long	sign;
	char	*start_nb;

	sign = 1;
	if (!ft_check_base(base))
		return (0);
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
