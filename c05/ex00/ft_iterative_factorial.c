/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:50:47 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/19 14:15:34 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	ret;

	ret = 1;
	i = 2;
	if (nb < 0)
		return (0);
	while (i <= nb)
	{
		ret = ret * i;
		i++;
	}
	return (ret);
}
