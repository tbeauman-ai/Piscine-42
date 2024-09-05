/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:35:54 by tbeauman          #+#    #+#             */
/*   Updated: 2024/09/02 12:35:56 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	solve_and_print(t_map *map)
{
	int	err;

	err = 0;
	if (!map)
		err = ft_puterr("map error\n");
	else
	{
		solve(map);
		free_map(map, map->height);
	}
	return (err);
}

int	main(int ac, char **av)
{
	t_map	*map;
	int		i;
	int		err;

	err = 0;
	if (ac == 1)
	{
		map = parse_stdin();
		err = solve_and_print(map);
	}
	i = 0;
	while (i++ < ac - 1)
	{
		map = parse_file(av[i]);
		err = solve_and_print(map);
	}
	return (err);
}
