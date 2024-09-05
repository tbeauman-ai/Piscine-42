/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:07:03 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/23 12:10:48 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_is_in(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

char	*ft_strndup(char *s, unsigned int n)
{
	char			*ret;
	unsigned int	i;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (n + 1));
	if (!ret)
		return (NULL);
	while (s[i] && i < n)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int	count_words(char *str, char *charset)
{
	int	count;

	count = 0;
	while (ft_is_in(*str, charset))
		str++;
	while (*str)
	{
		if (ft_is_in(*str, charset))
			str++;
		else
		{
			while (!ft_is_in(*str, charset))
				str++;
			count++;
		}
	}
	return (count);
}

char	**ft_fill_ret(char **tab, char *str, char *charset)
{
	int	i[2];
	int	n_word;

	i[0] = 0;
	n_word = 0;
	tab = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!tab)
		return (0);
	while (str[i[0]] != 0)
	{
		if (ft_is_in(str[i[0]], charset))
			i[0]++;
		else
		{
			i[1] = 0;
			while (!ft_is_in(str[i[0] + i[1]], charset))
				i[1]++;
			tab[n_word] = ft_strndup(str + i[0], i[1]);
			if (!tab[n_word++])
				return (0);
			i[0] = i[0] + i[1];
		}
	}
	tab[n_word] = 0;
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		len;

	ret = NULL;
	if (!str || !*str)
	{
		ret = (char **)malloc(sizeof(char *) * 1);
		if (!ret)
			return (0);
		ret[0] = 0;
	}
	else if (!charset || *charset == 0)
	{
		ret = (char **)malloc(sizeof(char *) * 2);
		if (!ret)
			return (0);
		len = 0;
		while (str[len])
			len++;
		ret[0] = ft_strndup(str, len);
		ret[1] = 0;
	}
	else
		ret = ft_fill_ret(ret, str, charset);
	return (ret);
}
