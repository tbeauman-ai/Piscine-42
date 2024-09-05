/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 08:38:19 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/18 08:38:30 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	char			*ret;

	i = 0;
	ret = dest;
	while (*dest)
		dest++;
	while (*src && i < nb)
	{
		*dest = *src;
		i++;
		dest++;
		src++;
	}
	*dest = 0;
	return (ret);
}
