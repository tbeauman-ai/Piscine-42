/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:35:17 by tbeauman          #+#    #+#             */
/*   Updated: 2024/09/02 12:35:19 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	parse_grid(t_map *map, char *line, int i)
{
	if (((i >= map->height || ft_strlen(line) - 1 != map->width))
		&& free_grid(map->grid, i) && rfree(map))
		return (0);
	map->grid[i] = (char *)malloc(sizeof(char) * (map->width + 1));
	if (!map->grid[i] && free_grid(map->grid, i) && rfree(map))
		return (0);
	if (i == map->height - 1 && line[map->width] != '\n'
		&& free_grid(map->grid, i + 1) && rfree(map))
		return (0);
	if (!bsq_memcpy(map->grid[i], line, map->width, map)
		&& free_grid(map->grid, i + 1) && rfree(map))
		return (0);
	return (1);
}

t_map	*fill_grid(int fd, char *line, t_map *ret)
{
	int	i;
	int	gnl;

	gnl = get_next_line(fd, &line);
	if (gnl == -1)
		return (0);
	i = 1;
	while (gnl == 1)
	{
		if (!parse_grid(ret, line, i++) && clear_file(fd, line))
			return (0);
		free(line);
		gnl = get_next_line(fd, &line);
		if (gnl == -1 && rfree(line) && free_map(ret, i))
			return (0);
	}
	if (i != ret->height && free_map(ret, i))
		return (0);
	if (gnl == -1 && free_map(ret, i))
		return (0);
	ret->grid[ret->height] = 0;
	return (ret);
}

t_map	*handle_two_first_lines(int fd, t_map **ret, char *line)
{
	if (ft_strlen(line) < 5 && clear_file(fd, line))
		return (0);
	if (!init_map(ret, line) && clear_file(fd, line))
		return (0);
	free(line);
	if (get_next_line(fd, &line) != -1)
	{
		if (line[ft_strlen(line) - 1] != '\n'
			&& rfree((*ret)->grid) && (rfree(*ret)) && rfree(line))
			return (0);
		(*ret)->width = ft_strlen(line) - 1;
		if (!(*ret)->width && rfree((*ret)->grid) && rfree(*ret) && rfree(line))
			return (0);
		(*ret)->grid[0] = (char *)malloc(sizeof(char) * ((*ret)->width + 1));
		if (!(*ret)->grid[0] && rfree((*ret)->grid)
			&& rfree((*ret)) && rfree(line))
			return (0);
		if (!bsq_memcpy((*ret)->grid[0], line, (*ret)->width, *ret)
			&& free_grid((*ret)->grid, 1) && rfree(*ret))
			return (0);
		free(line);
	}
	else if (rfree((*ret)->grid) && rfree((*ret)))
		return (0);
	return (*ret);
}

t_map	*parse_stdin(void)
{
	char	*line;
	t_map	*ret;

	line = 0;
	get_next_line(0, &line);
	if (!line)
		return (0);
	ret = 0;
	if (!handle_two_first_lines(0, &ret, line))
		return (0);
	if (!fill_grid(0, line, ret))
		return (0);
	return (ret);
}

t_map	*parse_file(char *filename)
{
	int		fd;
	char	*line;
	t_map	*ret;

	line = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	get_next_line(fd, &line);
	if (!line && !close(fd))
		return (0);
	ret = 0;
	if (!handle_two_first_lines(fd, &ret, line))
		return (0);
	if (!fill_grid(fd, line, ret))
		return (0);
	close(fd);
	return (ret);
}
