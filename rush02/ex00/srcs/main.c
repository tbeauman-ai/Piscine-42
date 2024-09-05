/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-vat <ande-vat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:03:52 by tbeauman          #+#    #+#             */
/*   Updated: 2024/09/01 16:43:46 by ande-vat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include "rush2.h"

int	puterror(int errnb)
{
	if (errnb == ERR_ARGNUM)
		print_error(ERRMSG_GENERIC);
	if (errnb == ERR_BADINPUT)
		print_error(ERRMSG_GENERIC);
	if (errnb == ERR_FOPEN)
		print_error(ERRMSG_DICT);
	if (errnb == ERR_FREAD)
		print_error(ERRMSG_DICT);
	if (errnb == ERR_MALLOC)
		print_error(ERRMSG_DICT);
	if (errnb == ERR_DICT)
		print_error(ERRMSG_DICT);
	return (errnb);
}

int	parse_and_write_number(t_dict dic, int ac, char **av)
{
	t_number	*nb;

	nb = 0;
	if (dic.next)
	{
		if (ac == 2)
			nb = parse_number(av[1]);
		if (ac == 3)
			nb = parse_number(av[2]);
		if (nb)
		{
			write_number(nb, dic.next);
			free_tnumber_list(nb);
		}
		return (0);
	}
	return (puterror(ERR_DICT));
}

int	parse_dic_and_handle_errors(t_dict *dic, int ac, char **av)
{
	int		ret;

	ret = process_args(ac, av, dic);
	if (!ret)
		ret = load_dic(dic);
	if (ret)
	{
		free_dic(dic->next);
		return (puterror(ret));
	}
	return (0);
}

int	main(int ac, char **av)
{
	int			ret;
	t_dict		dic;

	init(&dic);
	ret = parse_dic_and_handle_errors(&dic, ac, av);
	if (ret)
		return (ret);
	semi_trim_spaces(dic.next);
	fix_plus(dic.next);
	ret = parse_and_write_number(dic, ac, av);
	free_dic(dic.next);
	return (ret);
}
