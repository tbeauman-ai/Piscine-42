/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 00:11:36 by nmauvari          #+#    #+#             */
/*   Updated: 2024/08/31 01:48:47 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	do_error(int errcode)
{
	if (errcode == ERR_ARGVAL)
		write(2, ERR_ARGVAL_MSG, ERR_ARGVAL_LEN);
	return (errcode);
}
