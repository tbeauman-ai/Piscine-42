/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 10:50:33 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/18 11:26:57 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || \
		c == '\t' || c == '\v')
		return (1);
	else
		return (0);
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

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (*s1 && *s2 && *s1 == *s2 && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}

int	ft_parse(char *start_nb, int len_nb, int sign)
{
	int	ret;

	ret = 0;
	while (*start_nb >= '0' && *start_nb <= '9')
	{
		ret += ((int)*start_nb - 48) * ft_pow(10, len_nb-- - 1);
		start_nb++;
	}
	return (ret * sign);
}

int	ft_atoi(char *str)
{
	int		sign;
	int		len_nb;
	char	*start_nb;

	sign = 1;
	len_nb = 0;
	while (*str && ft_is_space(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
				sign = -sign;
			str++;
	}
	start_nb = str;
	while (*str >= '0' && *str <= '9')
	{
		len_nb++;
		str++;
	}
	return (ft_parse(start_nb, len_nb, sign));
}
