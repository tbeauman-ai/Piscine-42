/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:04:26 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/31 20:04:28 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"

int	handle_tens(t_dict *dico, t_write *w)
{
	if (w->n >= 20)
	{
		ft_strlcpy(w->tmp, w->trim, 2);
		w->tmp[1] = '0';
		w->tmp[2] = 0;
		w->found = find_in_dico(w->tmp, dico);
		if (w->found)
			ft_putstr(w->found->nb_str);
		w->trim[0] = w->trim[1];
		w->trim[1] = 0;
		w->n = ft_atoi(w->trim);
		if (w->n == 0)
			return (1);
		ft_putstr(" ");
	}
	else if (w->n >= 10)
	{
		w->found = find_in_dico(w->trim, dico);
		if (w->found)
			ft_putstr(w->found->nb_str);
		free(w->trim);
		free(w);
		return (1);
	}
	return (0);
}

void	shift_trim(t_write *w)
{
	w->trim[0] = w->trim[1];
	w->trim[1] = w->trim[2];
	w->trim[2] = 0;
	w->n = ft_atoi(w->trim);
}

int	handle_hundreds(t_dict *dico, t_write *w)
{
	if (w->n >= 100)
	{
		ft_strlcpy(w->tmp, w->trim, 2);
		w->found = find_in_dico(w->tmp, dico);
		if (w->found)
			print_found_with_space(w->found->nb_str);
		w->found = find_in_dico("100", dico);
		if (w->found)
			ft_putstr(w->found->nb_str);
		shift_trim(w);
		if (w->n < 10)
		{
			w->trim[0] = w->trim[1];
			w->trim[1] = 0;
		}
		if (w->n == 0)
		{
			free(w->trim);
			free(w);
			return (1);
		}
		ft_putstr(" ");
	}
	return (0);
}
