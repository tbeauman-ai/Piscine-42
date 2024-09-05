/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_dic_lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-vat <ande-vat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:27:01 by ande-vat          #+#    #+#             */
/*   Updated: 2024/09/01 14:27:16 by ande-vat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	match_pattern(t_dict *node)
{
	char	*s;

	s = node->nb_key;
	while (*s && (*s == ' ' || (*s >= 9 && *s <= 13)))
		s++;
	if (*s == '+')
		s++;
	if (*s < '0' || *s > '9')
		return (0);
	while (*s >= '0' && *s <= '9')
		s++;
	while (*s && *s != ':')
		*s++ = 0;
	if (*s != ':')
		return (0);
	*s++ = 0;
	while (*s == ' ')
		s++;
	if (!*s)
		return (0);
	node->nb_str = s;
	return (1);
}

int	filter_dic_lines(t_dict *previous)
{
	t_dict	*node;

	node = previous->next;
	while (node)
	{
		if (!match_pattern(node))
		{
			previous->next = free_dic_node(node);
			node = previous;
			return (ERR_DICT);
		}
		previous = node;
		node = node->next;
	}
	return (SUCCESS);
}
