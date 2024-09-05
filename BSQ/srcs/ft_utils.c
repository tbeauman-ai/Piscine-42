/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:27:45 by tbeauman          #+#    #+#             */
/*   Updated: 2024/09/03 17:27:46 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnew(size_t size)
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = (char *)malloc(size);
	if (!ret)
		return (NULL);
	while (i < size)
	{
		ret[i] = '\0';
		i++;
	}
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
	{
		if (!s1)
			return ((char *)s2);
		else
			return ((char *)s1);
	}
	ret = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	while (*s2 != '\0')
		ret[i++] = *s2++;
	ret[i] = '\0';
	return (ret);
}

void	print_grid(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		ft_putstr(map->grid[i]);
		ft_putstr("\n");
		i++;
	}
}

void	print_final_grid(t_map *map, int size, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			map->grid[y - i][x - j] = map->full;
	}
	print_grid(map);
}
