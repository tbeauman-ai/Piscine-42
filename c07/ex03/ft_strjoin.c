/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:32:15 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/22 11:29:33 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i])
		i++;
	while (*src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = 0;
	return (dest);
}

unsigned int	ft_strlen_tab(int size, char **strs)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < size)
	{
		ret += ft_strlen(strs[i]) + 1;
		i++;
	}
	return (ret);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen_tab(size, strs);
	ret = (char *)malloc(sizeof(char) * (len + size * ft_strlen(sep)));
	if (!ret)
		return (0);
	*ret = 0;
	i = 0;
	while (i < size)
	{
		ret = ft_strcat(ret, strs[i]);
		i++;
		if (i < size)
			ret = ft_strcat(ret, sep);
	}
	return (ret);
}
