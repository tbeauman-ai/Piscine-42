/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semi_trim_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-vat <ande-vat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:57:52 by ande-vat          #+#    #+#             */
/*   Updated: 2024/09/01 21:02:48 by ande-vat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"

void	fix_plus(t_dict *dico)
{
	while (dico)
	{
		if (dico->nb_digits[0] == '+')
			ft_strlcpy(dico->nb_digits, dico->nb_digits + 1, \
			ft_strlen(dico->nb_digits));
		dico = dico->next;
	}
}

void	semi_trim_spaces(t_dict *dico)
{
	int	i;
	int	j;

	while (dico)
	{
		i = 0;
		j = 0;
		while (dico->nb_str[i])
		{
			j = 0;
			while (dico->nb_str[i] != ' ' && dico->nb_str[i])
				i++;
			while (dico->nb_str[i + j] == ' ' && dico->nb_str[j])
				j++;
			if (dico->nb_str[i + j])
			{
				ft_strlcpy(dico->nb_str + i + 1, dico->nb_str + i + j,
					ft_strlen(dico->nb_str + i + j) + 1);
				i++;
			}
			else
				ft_strlcpy(dico->nb_str + i, "", 1);
		}
		dico = dico->next;
	}
}
