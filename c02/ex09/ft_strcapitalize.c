/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:03:43 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/17 18:03:55 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_alphanumeric(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int	ft_char_is_lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int	ft_char_is_uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (str);
	while (str[i])
	{
		if (ft_char_is_alphanumeric(str[i]))
		{
			if (ft_char_is_lowercase(str[i]))
				str[i] = str[i] - 32;
			while (ft_char_is_alphanumeric(str[i]))
			{
				i++;
				if (ft_char_is_uppercase(str[i]))
					str[i] = str[i] + 32;
			}
		}
		while (str[i] && !ft_char_is_alphanumeric(str[i]))
			i++;
	}
	return (str);
}
