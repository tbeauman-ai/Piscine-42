/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:04:42 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/20 13:07:00 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_in(char c, char *base);
int		ft_parse(char *start_nb, int len_nb, int sign, char *base);
int		ft_check_base(char *base);
long	ft_atol_base(char *str, char *base);
int		ft_len_base(char *b);

int	ft_sizeof_n_base(long n, char *base)
{
	int	i;
	int	lb;

	i = 0;
	lb = ft_len_base(base);
	while (n)
	{
		n = n / lb;
		i++;
	}
	return (i);
}

void	ft_check_neg(long *n, int *size, int *is_neg)
{
	if (*n < 0)
	{
		*size = 1;
		*n *= -1;
		*is_neg = 1;
	}
}

char	*handle_zero(char zero)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * 2);
	if (!ret)
		return (0);
	ret[0] = zero;
	ret[1] = 0;
	return (ret);
}

char	*ft_ltoa_base(long n, char *base)
{
	char	*ret;
	int		size;
	int		lb;
	int		is_neg;

	size = 0;
	is_neg = 0;
	ft_check_neg(&n, &size, &is_neg);
	size += ft_sizeof_n_base(n, base);
	if (n == 0)
		return (handle_zero(base[0]));
	ret = (char *)malloc(sizeof(char) * ft_sizeof_n_base(n, base));
	if (!ret)
		return (0);
	lb = ft_len_base(base);
	while (size)
	{
		ret[size - 1] = base[n % lb];
		n = n / lb;
		size--;
	}
	if (is_neg)
		ret[0] = '-';
	return (ret);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	long_nbr;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (0);
	long_nbr = ft_atol_base(nbr, base_from);
	return (ft_ltoa_base(long_nbr, base_to));
}
