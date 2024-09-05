/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:52:37 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/19 15:08:09 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int	i;

	i = ac - 1;
	if (ac > 0)
	{
		while (i > 0)
		{	
			write(1, av[i], ft_strlen(av[i]));
			write(1, "\n", 1);
			i--;
		}
	}
	return (0);
}
