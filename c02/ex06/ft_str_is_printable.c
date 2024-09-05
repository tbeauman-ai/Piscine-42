/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:43:03 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/17 14:43:05 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

int	ft_str_is_printable(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (!ft_char_is_printable(*str))
			return (0);
		str++;
	}
	return (1);
}
