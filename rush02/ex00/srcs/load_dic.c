/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_dic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ande-vat <ande-vat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 01:22:50 by nmauvari          #+#    #+#             */
/*   Updated: 2024/09/01 14:53:24 by ande-vat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	load_lines(t_buf **buf, t_dict *anchor)
{
	size_t	len;
	t_buf	*segmnt;
	char	*p;

	segmnt = skip_empty_lines(*buf);
	len = line_len(segmnt);
	while (len)
	{
		p = malloc(len + 1);
		if (!p || add_dic_node(anchor, p))
			return (ERR_MALLOC);
		p[len] = 0;
		segmnt = skip_empty_lines(fill_string(len, segmnt, p));
		len = line_len(segmnt);
	}
	*buf = segmnt;
	return (0);
}

int	load_dic(t_dict *anchor)
{
	int		fd;
	int		ret1;
	int		ret2;
	int		ret3;
	t_buf	*buf_a;

	fd = open(anchor->load_this, O_RDONLY);
	if (fd < 0)
		return (ERR_FOPEN);
	buf_a = NULL;
	ret1 = 0;
	ret2 = 0;
	while (!ret1 && !ret2)
	{
		ret1 = get_line(fd, &buf_a);
		if (ret1 <= 0)
			ret2 = load_lines(&buf_a, anchor);
	}
	free_tbuf_segments(&buf_a);
	close(fd);
	ret3 = filter_dic_lines(anchor);
	return ((ret1 > 0) * ret1 | (ret2 > 0) * ret2 | (ret3 > 0) * ret3);
}
