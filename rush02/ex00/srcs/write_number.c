/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 01:04:56 by tbeauman          #+#    #+#             */
/*   Updated: 2024/08/31 01:21:26 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"

int	write_three(t_number *nb, t_dict *dico)
{
	t_write	*w;

	w = init_t_write(nb);
	if (!w)
		return (0);
	if (w->n == 0)
		return (1);
	if (handle_hundreds(dico, w))
		return (1);
	if (handle_tens(dico, w))
		return (1);
	if (w->n > 0 && w->n < 10)
	{
		w->found = find_in_dico(w->trim, dico);
		if (w->found)
			ft_putstr(w->found->nb_str);
	}
	free(w->trim);
	free(w);
	return (1);
}

int	write_pow(t_number *nb, t_dict *dico)
{
	t_dict	*found;
	char	*to_find;
	int		i;

	to_find = (char *)malloc(sizeof(char) * (nb->pow + 2));
	if (!to_find)
		return (0);
	to_find[0] = '1';
	i = 1;
	while (i <= nb->pow)
		to_find[i++] = '0';
	to_find[i] = 0;
	found = find_in_dico(to_find, dico);
	free(to_find);
	if (found)
	{
		ft_putstr(" ");
		ft_putstr(found->nb_str);
	}
	else
		return (0);
	if (!is_last_paquet(nb))
		ft_putstr(" ");
	return (1);
}

int	write_zero(t_dict *dico)
{
	t_dict	*found;

	found = find_in_dico("0", dico);
	if (found)
	{
		ft_putstr(found->nb_str);
		ft_putstr("\n");
		return (1);
	}
	return (0);
}

int	handle_errors(t_number *nb, t_dict *dico)
{
	char	*to_find;
	t_dict	*found;
	int		i;

	while (nb->pow > 3)
	{
		to_find = (char *)malloc(sizeof(char) * (nb->pow + 2));
		if (!to_find)
			return (0);
		i = 1;
		*to_find = '1';
		while (i <= nb->pow)
			to_find[i++] = '0';
		to_find[i] = 0;
		found = find_in_dico(to_find, dico);
		free(to_find);
		if (!found)
		{
			print_error("Dict Error\n");
			return (0);
		}
		nb = nb->next;
	}
	return (1);
}

int	write_number(t_number *nb, t_dict *dico)
{
	if (!handle_errors(nb, dico))
		return (0);
	if (ft_strcmp(nb->str, "000") == 0)
	{
		nb = nb->next;
		return (write_zero(dico));
	}
	while (nb)
	{
		if (ft_strcmp(nb->str, "000") == 0)
		{
			nb = nb->next;
			continue ;
		}
		write_three(nb, dico);
		if (nb->next)
			if (!write_pow(nb, dico))
				return (0);
		nb = nb->next;
	}
	ft_putstr("\n");
	return (1);
}
