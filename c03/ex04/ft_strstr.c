/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 08:38:37 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/18 08:39:03 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*check_cases(char *str, char *to_find)
{
	if (!str || !to_find)
		return (NULL);
	else
		return (str);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*ret;
	char	*to_find_save;

	to_find_save = to_find;
	if (!str || !to_find || !*to_find)
		return (check_cases(str, to_find));
	while (*str)
	{
		if (*str == *to_find)
		{
			ret = str;
			while (*to_find && *str && *str == *to_find)
			{
				to_find++;
				str++;
			}
			if (!*to_find)
				return (ret);
			to_find = to_find_save;
			str = ret;
		}
		str++;
	}
	return (NULL);
}
