/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 00:45:09 by nmauvari          #+#    #+#             */
/*   Updated: 2024/08/31 01:53:53 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	init(t_dict *dic_anchor)
{
	dic_anchor->load_this = DEFAULT_DICTIONARY;
	dic_anchor->next = NULL;
}
