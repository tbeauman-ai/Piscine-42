/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:04:14 by tbeauman          #+#    #+#             */
/*   Updated: 2024/09/03 19:42:13 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}

int	ft_puterr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(2, s, i);
	return (1);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s += 1;
	}
	if ((char)c == '\0')
		return ((char *)s);
	else
		return (NULL);
}

int	*ft_gridnew(size_t size)
{
	int		*ret;
	size_t	i;

	i = 0;
	ret = malloc(size * sizeof(int));
	if (!ret)
		return (NULL);
	while (i < size)
	{
		ret[i] = 0;
		i++;
	}
	return (ret);
}
