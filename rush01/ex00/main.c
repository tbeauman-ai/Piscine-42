/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 07:48:14 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/24 07:55:04 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char			**parse(char *str, int n);
int				is_sol(char **sol, char **pb, int n);
int				solve(char **sol, char **pb, int pos, int n);
char			**malloc_nxn(unsigned int n);
unsigned int	ft_strlen(char *str);
void			ft_putstr(char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				ft_atoi(char *str);
void			print_pb(char **pb, int n);
void			print_sol(char **sol, int n);

char	**init_sol(unsigned int n)
{
	char			*src;
	char			**sol;
	unsigned int	i;

	i = 0;
	src = "000000000";
	sol = malloc_nxn(n);
	if (!sol)
		return (0);
	while (i < n)
	{
		ft_strlcpy(sol[i], src, n + 1);
		i++;
	}
	return (sol);
}

int	process(int ac, char **av)
{
	int		n;
	char	**sol;
	char	**pb;

	n = 4;
	if (ac == 3)
	{
		n = ft_atoi(av[2]);
		if (!(n >= 1 && n <= 9))
		{
			ft_putstr("Error\n");
			return (0);
		}
	}
	sol = init_sol(n);
	pb = parse(av[1], n);
	if (!pb)
		ft_putstr("Error\n");
	else if (!solve(sol, pb, 0, n))
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	if (ac == 2 || ac == 3)
		return (process(ac, av));
	else
		ft_putstr("Error\n");
	return (0);
}
