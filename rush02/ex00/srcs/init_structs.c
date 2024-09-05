/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-vat <ande-vat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:04:34 by tbeauman          #+#    #+#             */
/*   Updated: 2024/09/01 16:24:24 by ande-vat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"

t_number	*init_number(t_number *nb, char **number)
{
	while (**number == '0')
		(*number)++;
	if (**number != '0')
	{
		nb = (t_number *)malloc(sizeof(t_number));
		if (!nb)
			return (0);
		ft_strlcpy(nb->str, "000", 4);
		nb->pow = 0;
		nb->next = 0;
		return (nb);
	}
	else
		return (0);
	return (nb);
}

t_write	*init_t_write(t_number *nb)
{
	t_write	*w;

	w = (t_write *)malloc(sizeof(t_write));
	if (!w)
		return (0);
	ft_strlcpy(w->tmp, "000", 4);
	w->trim = trim_zeroes(nb->str);
	if (!w->trim)
	{
		free(w);
		return (0);
	}
	w->n = ft_atoi(w->trim);
	return (w);
}
