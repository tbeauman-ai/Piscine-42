/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:37:19 by tbeauman          #+#    #+#             */
/*   Updated: 2024/09/03 19:37:21 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	init_map(t_map **ret, char *fline)
{
	*ret = (t_map *)malloc(sizeof(t_map));
	if (!(*ret))
		return (0);
	(*ret)->height = ft_bsq_atoi(fline);
	if ((*ret)->height <= 0 && rfree(*ret))
		return (0);
	while (*(fline + 4) && *fline >= '0' && *fline <= '9')
		fline++;
	(*ret)->empty = fline[0];
	(*ret)->obst = fline[1];
	(*ret)->full = fline[2];
	if (ft_strlen(&fline[4]) && rfree(*ret))
		return (0);
	if (((*ret)->empty == (*ret)->obst || (*ret)->empty == (*ret)->full
			|| (*ret)->full == (*ret)->obst) && rfree(*ret))
		return (0);
	(*ret)->grid = (char **)malloc(sizeof(char *) * ((*ret)->height + 1));
	if (!(*ret)->grid && rfree(*ret))
		return (0);
	if ((*ret)->height <= 0 && rfree(*ret))
		return (0);
	return (1);
}
