/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:53:19 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/19 15:08:24 by tbeauman         ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort_args(int ac, char **av)
{
	int		i;
	int		j;
	char	*tmp;

	i = ac - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (ft_strcmp(av[j + 1], av[j]) < 0)
			{
				tmp = av[j + 1];
				av[j + 1] = av[j];
				av[j] = tmp;
			}
			j++;
		}
	i--;
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac > 0)
	{
		ft_sort_args(ac - 1, av + 1);
		while (i < ac)
		{	
			write(1, av[i], ft_strlen(av[i]));
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
