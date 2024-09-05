/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:21:20 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/17 18:00:15 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_str_is_numeric(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (!ft_char_is_numeric(*str))
			return (0);
		str++;
	}
	return (1);
}
