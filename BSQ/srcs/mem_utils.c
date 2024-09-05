/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:44:33 by tbeauman          #+#    #+#             */
/*   Updated: 2024/09/03 17:44:42 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s1;
	char	*s2;

	s1 = (char *)dst;
	s2 = (char *)src;
	while (n--)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	return (dst);
}

void	*bsq_memcpy(void *dst, const void *src, size_t n, t_map *map)
{
	char	*s1;
	char	*s2;

	s1 = (char *)dst;
	s2 = (char *)src;
	while (n--)
	{
		if (*s2 == map->empty || *s2 == map->obst)
			*s1 = *s2;
		else
			return (0);
		s1++;
		s2++;
	}
	*s1 = 0;
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp;

	tmp = (char *)malloc(len);
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, src, len);
	ft_memcpy(dst, tmp, len);
	free(tmp);
	return (dst);
}
