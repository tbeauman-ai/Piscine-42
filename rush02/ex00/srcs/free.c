/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:04:03 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/31 20:04:04 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"

void	free_tnumber_list(t_number *list)
{
	t_number	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void	free_t_dict(t_dict *dico)
{
	t_dict	*tmp;

	while (dico)
	{
		tmp = dico;
		dico = dico->next;
		free(tmp);
	}
}
