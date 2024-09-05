/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:09:24 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/19 12:11:42 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	ret;
	int	i;

	i = 0;
	ret = 1;
	if (power < 0)
		return (0);
	while (i < power)
	{
		ret = ret * nb;
		i++;
	}
	return (ret);
}
