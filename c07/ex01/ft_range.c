/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:13:36 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/19 20:32:02 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ret;
	int	i;

	i = min;
	if (min >= max)
		return (0);
	ret = (int *)malloc(sizeof(int) * (max - min));
	if (!ret)
		return (0);
	while (i < max)
	{
		ret[i - min] = i;
		i++;
	}
	return (ret);
}
