/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-vat <ande-vat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:04:43 by tbeauman          #+#    #+#             */
/*   Updated: 2024/09/01 16:24:31 by ande-vat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"

void	get_pow_and_increment_number(char **number, t_number *nb)
{
	if (ft_strlen(*number) % 3)
	{
		nb->pow = 3 * (ft_strlen(*number) / 3);
		*number += ft_strlen(*number) % 3;
	}
	else
	{
		nb->pow = ft_strlen(*number) - 3;
		*number += 3;
	}
}

int	actually_parse_number(char *number, t_number *nb)
{
	while (*number)
	{
		if (ft_strlen(number) % 3)
			ft_strlcpy(nb->str + (3 - ft_strlen(number) % 3), number,
				ft_strlen(number) % 3 + 1);
		else
			ft_strlcpy(nb->str, number, 4);
		if (ft_strlen(number) <= 3)
		{
			nb->next = 0;
			break ;
		}
		nb->next = (t_number *)malloc(sizeof(t_number));
		if (!nb->next)
			return (0);
		get_pow_and_increment_number(&number, nb);
		if (*number)
			ft_strlcpy(nb->next->str, "000", 4);
		nb = nb->next;
	}
	return (1);
}

t_number	*parse_number(char *number)
{
	t_number	*nb;
	t_number	*head;

	nb = 0;
	if (!is_positive_integer(number))
	{
		print_error("Error\n");
		return (0);
	}
	nb = init_number(nb, &number);
	if (!nb)
		return (0);
	head = nb;
	if (!actually_parse_number(number, nb))
	{
		free_tnumber_list(head);
		return (0);
	}
	nb = 0;
	return (head);
}
