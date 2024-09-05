/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 07:31:05 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/24 07:32:04 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*ret;
	char	*tmp;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	*ret = 0;
	tmp = ret;
	while (*src)
	{
		*tmp = *src;
		tmp++;
		src++;
	}
	*tmp = 0;
	return (ret);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*ret;
	int			i;

	ret = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!ret)
		return (0);
	ret[ac].str = 0;
	i = 0;
	while (i < ac)
	{
		ret[i].size = ft_strlen(av[i]);
		ret[i].str = av[i];
		ret[i].copy = ft_strdup(av[i]);
		if (!ret[i].copy)
			return (0);
		i++;
	}
	return (ret);
}
