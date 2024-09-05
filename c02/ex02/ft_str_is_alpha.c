/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:21:20 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/17 18:30:35 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	ft_str_is_alpha(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (!ft_char_is_alpha(*str))
			return (0);
		str++;
	}
	return (1);
}
