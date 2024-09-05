/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 02:20:54 by nmauvari          #+#    #+#             */
/*   Updated: 2024/09/01 02:27:32 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	add_dic_node(t_dict *anchor, char *str)
{
	t_dict	*new;

	new = malloc(sizeof(t_dict));
	if (!new)
	{
		free(str);
		return (ERR_MALLOC);
	}
	new->next = anchor->next;
	new->nb_key = str;
	anchor->next = new;
	return (SUCCESS);
}

t_dict	*free_dic_node(t_dict *node)
{
	t_dict	*next;

	next = node->next;
	free(node->nb_key);
	free(node);
	return (next);
}
