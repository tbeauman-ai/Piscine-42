/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:26:08 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/28 19:27:27 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_add(int a, int b);
int		ft_sub(int a, int b);
int		ft_mul(int a, int b);
int		ft_div(int a, int b);
int		ft_mod(int a, int b);
int		ft_atoi(char *str);
void	ft_putop(int nb);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int	check_arguments(int ac, char **av)
{
	if (ac != 4)
		return (0);
	if (ft_strlen(av[2]) != 1)
	{
		ft_putstr("0\n");
		return (0);
	}
	if (!(av[2][0] == '+' || av[2][0] == '-' || av[2][0] == '*'
			|| av[2][0] == '/' || av[2][0] == '%'))
	{
		ft_putstr("0\n");
		return (0);
	}
	return (1);
}

void	ft_doop(char **av, int (*ops[5])(int, int))
{
	int	a;
	int	b;

	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	if (av[2][0] == '+')
		ft_putop(ops[0](a, b));
	if (av[2][0] == '-')
		ft_putop(ops[1](a, b));
	if (av[2][0] == '*')
		ft_putop(ops[2](a, b));
	if (av[2][0] == '/' && b == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return ;
	}
	if (av[2][0] == '%' && b == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return ;
	}
	if (av[2][0] == '/')
		ft_putop(ops[3](a, b));
	if (av[2][0] == '%')
		ft_putop(ops[4](a, b));
}

int	main(int ac, char **av)
{
	int	(*ops[5])(int, int);

	ops[0] = &ft_add;
	ops[1] = &ft_sub;
	ops[2] = &ft_mul;
	ops[3] = &ft_div;
	ops[4] = &ft_mod;
	if (!check_arguments(ac, av))
		return (0);
	else
		ft_doop(av, ops);
	return (1);
}
