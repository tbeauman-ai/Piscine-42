/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:16:37 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/25 10:26:06 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str);

int	check_parse_errors(char *str, int n)
{
	if ((int)ft_strlen(str) != 2 * n * 4 - 1)
		return (0);
	return (1);
}

char	**malloc_nxn(int n)
{
	char	**ret;
	int		i;

	i = 0;
	ret = (char **)malloc(sizeof(char *) * (n + 1));
	if (!ret)
		return (0);
	while (i < n)
	{
		ret[i] = (char *)malloc(sizeof(char) * (n + 1));
		if (!ret[i])
		{
			while (i > 0)
			{
				free(ret[i]);
				i--;
			}
			free(ret);
			return (0);
		}
		i++;
	}
	return (ret);
}

char	**malloc_pb(int n)
{
	char	**ret;
	int		i;

	i = 0;
	ret = (char **)malloc(sizeof(char *) * (5));
	if (!ret)
		return (0);
	while (i < 4)
	{
		ret[i] = (char *)malloc(sizeof(char) * (n + 1));
		if (!ret[i])
		{
			while (i > 0)
			{
				free(ret[i]);
				i--;
			}
			free(ret);
			return (0);
		}
		i++;
	}
	ret[i] = 0;
	return (ret);
}

void	free_nxn(char **p, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(p[i]);
		i++;
	}
	free(p);
}

char	**parse(char *str, int n)
{
	char	**ret;
	int		i;

	i = -1;
	if (check_parse_errors(str, n) == 0)
		return (0);
	ret = malloc_pb(n);
	if (!ret)
		return (0);
	while (str[++i])
	{
		if (i % 2 == 0)
		{
			if (str[i] >= '1' && str[i] <= '0' + n)
				ret[(i / 2) / n][(i / 2) % n] = str[i];
			else
				return (0);
		}
		else if (str[i] != ' ')
			return (0);
	}
	return (ret);
}
