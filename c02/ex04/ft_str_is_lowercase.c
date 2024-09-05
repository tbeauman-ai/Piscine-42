/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:43:03 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/17 14:43:05 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int	ft_str_is_lowercase(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (!ft_char_is_lowercase(*str))
			return (0);
		str++;
	}
	return (1);
}
