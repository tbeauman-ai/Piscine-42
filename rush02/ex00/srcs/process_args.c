/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 00:13:33 by nmauvari          #+#    #+#             */
/*   Updated: 2024/08/31 02:41:10 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*eat_leading_and_sign(char *s, int *sign)
{
	int	tic;

	tic = 0;
	s--;
	while (*++s && (*s == ' ' || *s == '\t' || *s == '\n'))
		;
	s--;
	while (*++s && (*s == '-' || *s == '+'))
		if (*s == '-')
			tic = !tic;
	*sign = tic;
	return (s);
}

int	process_args(int ac, char **av, t_dict *dic_a)
{
	if (ac > 3 || ac < 2)
		return (ERR_ARGNUM);
	if (ac == 3)
		dic_a->load_this = av[1];
	return (0);
}
