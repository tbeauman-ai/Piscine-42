/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:34:10 by tbeauman          #+#    #+#             */
/*   Updated: 2024/09/03 17:34:11 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	free_grid(char **grid, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		free(grid[j]);
		j++;
	}
	free(grid);
	return (1);
}

char	free_map(t_map *map, int i)
{
	free_grid(map->grid, i);
	free(map);
	return (1);
}

char	free_maps(t_map **maps, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (maps[i])
			free_map(maps[i], maps[i]->height);
		i++;
	}
	free(maps);
	return (1);
}

char	clear_file(int fd, char *line)
{
	free(line);
	while (get_next_line(fd, &line))
		free(line);
	close(fd);
	return (1);
}

char	rfree(void *ptr)
{
	if (ptr)
		free(ptr);
	return (1);
}
