/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 22:13:29 by tbeauman          #+#    #+#             */
/*   Updated: 2024/09/04 16:44:45 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_char_hexa(unsigned char c)
{
	char	*str;

	str = "0123456789abcdef";
	write(1, &str[c / 16], 1);
	write(1, &str[c % 16], 1);
}

void	ft_print_hexa(unsigned long long n, unsigned int nb_digits)
{
	int		i;
	char	*str;

	i = 0;
	str = "0123456789abcdef";
	if (n > 0)
	{
		ft_print_hexa(n / 16, nb_digits + 1);
		write(1, &str[n % 16], 1);
	}
	if (n == 0 && nb_digits < 16)
	{
		ft_print_hexa(n, nb_digits + 1);
		write(1, "0", 1);
	}
}

void	ft_print_str(char *straddr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (straddr[i] >= 32 && straddr[i] <= 126)
			write(1, &straddr[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_print_line(void *addr, unsigned int size)
{
	unsigned int	i;
	char			*straddr;

	i = 0;
	straddr = (char *)addr;
	ft_print_hexa((unsigned long long)addr, 0);
	write (1, ": ", 2);
	while (i < size)
	{
		ft_print_char_hexa(straddr[i]);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	ft_print_str(straddr, size);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (!addr)
		return (addr);
	while (i < size / 16)
	{
		if (size - i * 16 > 16)
			ft_print_line(addr + i * 16, 16);
		else
			ft_print_line(addr + i * 16, size - i * 16);
		i += 1;
	}
	if (size - i * 16)
		ft_print_line(addr + i * 16, size - i * 16);
	return (addr);
}
