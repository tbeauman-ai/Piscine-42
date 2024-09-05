/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:05:16 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/19 09:54:06 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_char_is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

void	ft_print_hexadecimal(unsigned char c)
{
	char	*str;

	str = "0123456789abcdef";
	ft_putchar(str[c / 16]);
	ft_putchar(str[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		if (ft_char_is_printable(*str))
			ft_putchar(*str);
		else
		{
			ft_putchar(92);
			ft_print_hexadecimal(*str);
		}
		str++;
	}
}
