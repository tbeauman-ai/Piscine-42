/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:49:40 by mle-flem          #+#    #+#             */
/*   Updated: 2024/09/02 16:44:29 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**free_solve_grid(int **grid, int height)
{
	int	i;

	if (grid)
	{
		i = -1;
		while (++i < height)
			free(grid[i]);
		free(grid);
	}
	return (NULL);
}

int	**new_grid(t_map *map)
{
	t_grid_coords	g;

	g.grid = malloc((map->height + 1) * sizeof(int *));
	if (!g.grid)
		return (free_solve_grid(g.grid, 0));
	g.y = -1;
	while (++g.y < (map->height + 1))
	{
		g.grid[g.y] = malloc((map->width + 1) * sizeof(int));
		if (!g.grid[g.y])
			return (free_solve_grid(g.grid, (g.y + 1)));
	}
	g.y = -1;
	while (++g.y < (map->height + 1))
	{
		g.x = -1;
		while (++g.x < (map->width + 1))
		{
			if (g.y == 0 || g.x == 0)
				g.grid[g.y][g.x] = 0;
			else
				g.grid[g.y][g.x] = (map->grid[g.y - 1][g.x - 1] == map->empty);
		}
	}
	return (g.grid);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	actually_solve(t_map *map, t_solver *s)
{
	s->i = 0;
	while (++s->i <= map->height)
	{
		s->j = 0;
		while (++s->j <= map->width)
		{
			s->tmp = s->grid[s->j];
			if (map->grid[s->i - 1][s->j - 1] == map->obst)
				s->grid[s->j] = 0;
			else
			{
				s->grid[s->j] = min(min(s->grid[s->j - 1],
							s->grid[s->j]), s->prev) + 1;
				if (s->grid[s->j] > s->max[0])
				{
					s->max[0] = s->grid[s->j];
					s->max[1] = s->i - 1;
					s->max[2] = s->j - 1;
				}
			}
			s->prev = s->tmp;
		}
	}
}

int	solve(t_map *map)
{
	t_solver	s;

	s.grid = ft_gridnew(map->width + 1);
	if (!s.grid)
		return (-1);
	s.prev = 0;
	s.max[0] = 0;
	s.max[1] = -1;
	s.max[2] = -1;
	actually_solve(map, &s);
	print_final_grid(map, s.max[0], s.max[2], s.max[1]);
	free(s.grid);
	return (0);
}
