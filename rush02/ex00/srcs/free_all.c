/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-vat <ande-vat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 01:35:43 by nmauvari          #+#    #+#             */
/*   Updated: 2024/09/01 16:42:01 by ande-vat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	free_dic(t_dict *dic)
{
	t_dict	*next;

	while (dic)
	{
		next = dic->next;
		free(dic->nb_key);
		free(dic);
		dic = next;
	}
}
