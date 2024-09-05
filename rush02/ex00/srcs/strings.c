/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-vat <ande-vat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:38:08 by ande-vat          #+#    #+#             */
/*   Updated: 2024/08/31 18:17:51 by ande-vat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_error(char *str)
{
	write(2, str, str_len(str));
}

char	*str_cat(char *s1, char *s2, int size)
{
	int	i;
	int	j;

	i = str_len(s1);
	j = 0;
	while (s2[j] && (j < size || size == 0))
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*strdup_pos(char *str, int start, int end)
{
	char	*ret;
	int		i;

	i = 0;
	if (end != 0)
		ret = malloc((end - start) + 1);
	else
		ret = malloc(str_len(str) - start + 1);
	if (end - start <= 0 && end != 0)
		return (NULL);
	while (start != end || end == 0)
	{
		if (!str[start])
			break ;
		ret[i] = str[start];
		i++;
		start++;
	}
	ret[i] = '\0';
	return (ret);
}

char	**split_semicolon(char *str)
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char *) * 2);
	while (str[i] != ':' && str[i])
		i++;
	if (!str[i])
		return (NULL);
	tab[0] = strdup_pos(str, 0, i);
	tab[1] = strdup_pos(str, i + 1, 0);
	return (tab);
}
