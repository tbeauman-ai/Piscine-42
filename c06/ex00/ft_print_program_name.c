/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:46:21 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/20 18:05:51 by tbeauman         ###   ########.fr       */
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
	if (ac > 0)
	{
		write(1, av[0], ft_strlen(av[0]));
		write(1, "\n", 1);
	}
	return (0);
}
