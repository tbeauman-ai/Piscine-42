/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:01:32 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/17 18:02:24 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (str);
	while (str[i])
	{
		if (ft_char_is_lowercase(str[i]))
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
